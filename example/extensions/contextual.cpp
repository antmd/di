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
            using given = typename decltype(dependency)::given;
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
    auto operator ->() const {
        return std::make_unique<type_<di::aux::type_list<T>>>();
    }

    auto operator()() {
        return std::make_unique<type_<di::aux::type_list<T>>>();
    }
};

struct context_ {
    template<class T>
    auto operator=(std::unique_ptr<T> t) const {
        return *t;
    }

    template<class T>
    auto operator=(T t) const {
        return t;
    }
};

context_ context;

struct then_ {
    template<class T>
    T then(T) {
        return {};
    }
};

template<class T>
then_ when(T&&) {
    return {};
}

struct contextual {
    template<class... Ts>
    contextual(Ts&&...) {
    }


    template<class T, class TDependency, class... TCtor>
    auto operator()(T&&, TDependency&&, TCtor&&...) const {
        return 0;
    }
};

int main() {
    auto injector = di::make_injector<build_types>(
        di::bind<int>.to(
            contextual{
                when(context = type<a>()).then(1)
              , when(context = type<a>() -> type<b>()).then(2)
              , when(context = type<a>() -> type<b>() -> type<c>()).then(3)
            }
        )
    );

    injector.create<a>();
}

//]

