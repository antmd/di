//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

//[contextual
//<-
#include <cassert>
#include <typeinfo>
#include <map>
//->
#define BOOST_DI_CFG_NO_PREPROCESSED_HEADERS
#include <boost/di.hpp>

namespace di = boost::di;

struct c {
    c(int i) {
        assert(i == 3);
    }
};

struct b {
    b(c, int i) {
        assert(i == 2);
    }
};

struct a {
    a(b, int i) {
        assert(i == 1);
    }
};

template<class>
struct get_type;

template<class T>
struct get_type<di::aux::type<T>> {
    using type = T;
};

class build_types : public di::config {
public:
    auto policies() noexcept {
        return di::make_policies([&](auto type, auto dependency, auto... ctor) {
            using arg = typename decltype(type)::type;
            types[v[i - 1]].push_back(&typeid(arg));
            auto ctor_size = sizeof...(ctor);
            while (ctor_size--) {
                v.insert((v.begin()+i), v[i-1]+1);
            }
            ++i;
        });
    }

    std::map<int, std::vector<const std::type_info*>> types;

private:
    std::vector<int> v = { 0 };
    int i = 1;
};

template<class>
struct type_;

template<class... Ts>
struct type_<di::aux::type_list<Ts...>> {
    template<class T>
    auto type() {
        return std::make_unique<type_<di::aux::type_list<Ts..., T>>>();
    }
};

template<class T>
struct type {
    auto operator->() const {
        return std::make_unique<type_<di::aux::type_list<T>>>();
    }

    auto operator()() {
        return std::make_unique<type_<di::aux::type_list<T>>>();
    }
};

struct context_ {
    template<class T>
    auto operator=(std::unique_ptr<T> object) const {
        return *object;
    }

    template<class T>
    auto operator=(T object) const {
        return object;
    }
};

context_ context;

template<class T, class R>
struct all {
    using type = T;
    T object;
};

template<class R>
struct then_ {
    template<class T>
    auto then(T value) {
        return all<T, R>{value};
    }
};

template<class T>
then_<T> when(T&&) {
    return {};
}

template<class TResult>
struct contextual {
    template<class... Ts>
    explicit contextual(Ts&&... args)
        : types{std::make_pair(&typeid(typename Ts::type), args.object)...}
    { }

    template<class... TCtor>
    using make_type_list = di::aux::type_list<typename get_type<TCtor>::type...>;

    template<class TInjector>
    auto operator()(const TInjector& injector) const -> TResult {
        const auto& types = injector.types;
        //const auto it = types.find(&typeid(make_type_list<TCtor...>));
        //std::cout << typeid(make_type_list<TCtor...>).name() << std::endl;
        //if (it != types.end()) {
            //std::cout << "dupa: " << it->second << std::endl;
            //return it->second;
        //}

        return 42;
    }

    std::map<const std::type_info*, TResult> types;
};

int main() {
    auto injector = di::make_injector<build_types>(
        di::bind<int>.to(
            contextual<int>{
                when(context = type<a>()).then(1)
              //, when(context = type<a>() -> type<b>()).then(2)
              //, when(context = type<a>() -> type<b>() -> type<c>()).then(3)
            }
        )
    );

    injector.create<a>();
}

//]

