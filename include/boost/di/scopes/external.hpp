//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef BOOST_DI_SCOPES_EXTERNAL_HPP
#define BOOST_DI_SCOPES_EXTERNAL_HPP

#include <memory>
#include "boost/di/aux_/type_traits.hpp"
#include "boost/di/wrappers/unique.hpp"
#include "boost/di/wrappers/shared.hpp"
#include "boost/di/config.hpp"

namespace boost { namespace di { namespace scopes {

BOOST_DI_HAS_TYPE(result_type);
BOOST_DI_HAS_METHOD(call_operator, operator());

template<class T, class... Ts>
using is_lambda_expr =
    std::integral_constant<
        bool
      , has_call_operator<T, Ts...>::value &&
       !has_result_type<T>::value
    >;

template<class T>
struct wrapper_traits {
    using type = wrappers::unique<T>;
};

template<class T>
struct wrapper_traits<std::shared_ptr<T>> {
    using type = wrappers::shared<T>;
};

template<class T>
using wrapper_traits_t =
    typename wrapper_traits<T>::type;

class external {
    struct injector {
        template<class T> T create() const;
        //core::pool<> policies() const;
        //int provider() const;
    };

public:
    static constexpr auto priority = true;

    template<class TExpected, class, class = void>
    struct scope {
        template<class, class TProvider>
        TExpected try_create(const TProvider&);

        template<class, class TProvider>
        auto create(const TProvider&) const noexcept {
            return wrappers::unique<TExpected>{object_};
        }

        TExpected object_;
    };

    template<class TExpected, class TGiven>
    struct scope<TExpected, std::reference_wrapper<TGiven>> {
        using is_ref = void;

        template<class, class TProvider>
        std::reference_wrapper<TGiven> try_create(const TProvider&);

        template<class, class TProvider>
        auto create(const TProvider&) const noexcept {
            return object_;
        }

        std::reference_wrapper<TGiven> object_;
    };

    template<class TExpected, class TGiven>
    struct scope<TExpected, std::shared_ptr<TGiven>> {
        template<class, class TProvider>
        wrappers::shared<TGiven> try_create(const TProvider&);

        template<class, class TProvider>
        auto create(const TProvider&) const noexcept {
            return wrappers::shared<TGiven>{object_};
        }

        std::shared_ptr<TGiven> object_;
    };

    template<class TExpected, class TGiven>
    struct scope<
        TExpected
      , TGiven
      , std::enable_if_t<
            !is_lambda_expr<TGiven, const injector&>::value &&
            !has_call_operator<TExpected>::value &&
             has_call_operator<TGiven>::value
        >
    > {
        template<class T, class TProvider>
        auto try_create(const TProvider&) -> wrapper_traits_t<decltype(std::declval<TGiven>()())>;

        template<class, class TProvider>
        auto create(const TProvider&) const noexcept {
            using wrapper = wrapper_traits_t<decltype(std::declval<TGiven>()())>;
            return wrapper{object_()};
        }

        TGiven object_;
    };

    template<class TExpected, class TGiven>
    struct scope<TExpected, TGiven, std::enable_if_t<is_lambda_expr<TGiven, const injector&>::value>> {
        template<class T, class TProvider>
        T try_create(const TProvider&);

        template<class, class TProvider>
        auto create(const TProvider& provider) const noexcept {
            using wrapper = wrapper_traits_t<decltype((object_)(provider.injector_))>;
            return wrapper{(object_)(provider.injector_)};
        }

        TGiven object_;
    };

#if !defined(_MSC_VER)
    template<class TExpected, class TGiven>
    struct scope<TExpected, TGiven, std::enable_if_t<is_lambda_expr<TGiven, const injector&, const aux::type<aux::none_t>&>::value>> {
        template<class T, class TProvider>
        T try_create(const TProvider&);

        template<class T, class TProvider>
        auto create(const TProvider& provider) const noexcept {
            using wrapper = wrapper_traits_t<decltype((object_)(provider.injector_, aux::type<T>{}))>;
            return wrapper{(object_)(provider.injector_, aux::type<T>{})};
        }

        TGiven object_;
    };
#endif
};

}}} // boost::di::scopes

#endif

