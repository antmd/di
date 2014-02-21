//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Preprocessed version of "boost::di"
// DO NOT modify by hand!
//
#ifndef BOOST_DI_AUX_PREPROCESSED_DI_HPP
#define BOOST_DI_AUX_PREPROCESSED_DI_HPP

#include <vector>
#include <utility>
#include <typeinfo>
#include <string>
#include <map>
#include <cassert>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_rvalue_reference.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_polymorphic.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_enum.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/is_arithmetic.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/type.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/ref.hpp>
#include <boost/non_type.hpp>
#include <boost/none_t.hpp>
#include <boost/mpl/void.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/max.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/iterator_range.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/count_if.hpp>
#include <boost/mpl/count.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/aux_/yes_no.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/accumulate.hpp>
#include <boost/function.hpp>
#include "boost/di/inject.hpp"
#include "boost/di/aux_/memory.hpp"
#include <boost/config.hpp>

namespace boost {
namespace di {
namespace type_traits {

template<typename T>
struct remove_accessors
    : remove_cv<
         typename remove_pointer<
             typename remove_reference<T>::type
         >::type
      >
{ };

}
}
}

namespace boost {
namespace di {
namespace type_traits {

template<typename>
struct make_plain;

BOOST_MPL_HAS_XXX_TRAIT_DEF(element_type)
BOOST_MPL_HAS_XXX_TRAIT_DEF(named_type)

template<typename T, typename = void>
struct deref_type
{
    typedef T type;
};

template<typename T>
struct deref_type<T, typename enable_if<has_element_type<T> >::type>
{
    typedef typename T::element_type type;
};

template<typename T>
struct deref_type<T, typename enable_if<has_named_type<T> >::type>
{
    typedef typename make_plain<typename T::named_type>::type type;
};

template<typename T>
struct make_plain
    : deref_type<
        typename remove_accessors<
            typename deref_type<
                typename remove_accessors<T>::type
            >::type
        >::type
    >
{ };

}
}
}

namespace boost {
namespace di {
namespace type_traits {

template<typename T, typename U = mpl::_1>
struct is_same_base_of
    : mpl::or_<
          is_base_of<U, T>
        , is_same<U, T>
      >
{ };

}
}
}


    namespace boost {
    namespace di {
    namespace type_traits {

    template<typename>
    struct parameter_types;

    template<typename R>
    struct parameter_types<R(*)()>
    {
        typedef R result_type;
        typedef mpl::vector0<> type;
    };

    template<typename R, typename T>
    struct parameter_types<R(T::*)()>
    {
        typedef R result_type;
        typedef mpl::vector0<> type;
    };

    template<typename R, typename T>
    struct parameter_types<R(T::*)() const>
    {
        typedef R result_type;
        typedef mpl::vector0<> type;
    };

    template<typename R, typename Args0>
    struct parameter_types<R(*)( Args0)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0> type;
    };

    template<typename R, typename T, typename Args0>
    struct parameter_types<R(T::*)( Args0)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0> type;
    };

    template<typename R, typename T, typename Args0>
    struct parameter_types<R(T::*)( Args0) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0> type;
    };

    template<typename R, typename Args0 , typename Args1>
    struct parameter_types<R(*)( Args0 , Args1)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1>
    struct parameter_types<R(T::*)( Args0 , Args1)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1>
    struct parameter_types<R(T::*)( Args0 , Args1) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2>
    struct parameter_types<R(*)( Args0 , Args1 , Args2)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18> type;
    };

    template<typename R, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    struct parameter_types<R(*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19)>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19> type;
    };

    template<typename R, typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    struct parameter_types<R(T::*)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19) const>
    {
        typedef R result_type;
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19> type;
    };

    }
    }
    }


    namespace boost {
    namespace di {
    namespace type_traits {

    template<typename, typename>
    class has_ctor;

        template<typename T>
        class has_ctor<T, mpl::int_<1> >
        {
            struct any_type
            {
                typedef typename type_traits::make_plain<T>::type plain_t;

                template<
                    typename U
                  , typename PU = typename type_traits::make_plain<U>::type
                  , typename = typename disable_if<type_traits::is_same_base_of<PU, plain_t> >::type
                >
                operator U() const;
            };

            template<typename U>
            static mpl::aux::yes_tag test(BOOST_TYPEOF_TPL(U(any_type()))*);

            template<typename U>
            static mpl::aux::no_tag test(...);

        public:
            typedef has_ctor type;
            BOOST_STATIC_CONSTANT(
                bool
              , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
            );
        };

    template<typename T>
    class has_ctor<T, mpl::int_<2> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<3> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<4> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<5> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<6> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<7> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<8> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<9> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<10> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<11> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<12> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<13> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<14> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<15> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<16> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<17> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<18> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<19> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename T>
    class has_ctor<T, mpl::int_<20> >
    {
        struct any_type
        {
            template<typename U> operator U&() const;

            template<typename U> operator U();
        };

        template<typename U>
        static mpl::aux::yes_tag test(
            BOOST_TYPEOF_TPL(U(
                any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() , any_type() )
            )*
        );

        template<typename U>
        static mpl::aux::no_tag test(...);

    public:
        typedef has_ctor type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
        );
    };

    }
    }
    }


namespace boost {
namespace di {
namespace detail {

struct any_type { };

template<typename T>
struct get_int
{
    typedef mpl::int_<T::value> type;
};

template<typename T>
struct get_longest_ctor
    : mpl::fold<
        mpl::range_c<int, 1, 20 + 1>
      , mpl::int_<0>
      , mpl::if_<
            type_traits::has_ctor<T, get_int<mpl::_2> >
          , mpl::_2
          , mpl::_1
        >
      >::type
{ };

}

template<typename T>
struct ctor_traits
    : mpl::fold<
          mpl::range_c<int, 0, detail::get_longest_ctor<T>::value>
        , mpl::vector0<>
        , mpl::push_back<mpl::_1, detail::any_type>
      >
{ };

template<typename T>
struct ctor_traits<std::basic_string<T> >
{
    static void BOOST_DI_INJECTOR();
};

namespace type_traits {

template<typename T>
class has_BOOST_DI_INJECTOR
{
    struct base_impl { void BOOST_DI_INJECTOR(...) { } };
    struct base
        : base_impl
        , mpl::if_<is_class<T>, T, mpl::void_>::type
    { base() { } };

    template<typename U>
    static mpl::aux::no_tag test(
        U*
      , non_type<void (base_impl::*)(...), &U::BOOST_DI_INJECTOR>* = 0
    );

    static mpl::aux::yes_tag test(...);

public:
    typedef has_BOOST_DI_INJECTOR type;

    BOOST_STATIC_CONSTANT(
        bool
      , value = sizeof(test((base*)(0))) == sizeof(mpl::aux::yes_tag)
    );
};

template<typename T, typename = void>
struct ctor_traits
    : di::ctor_traits<T>::type
{ };

template<typename T>
struct ctor_traits<T, typename enable_if<has_BOOST_DI_INJECTOR<di::ctor_traits<T> > >::type>
    : parameter_types<BOOST_TYPEOF_TPL(&di::ctor_traits<T>::BOOST_DI_INJECTOR)>::type
{ };

template<typename T>
struct ctor_traits<T, typename enable_if<has_BOOST_DI_INJECTOR<T> >::type>
    : parameter_types<BOOST_TYPEOF_TPL(&T::BOOST_DI_INJECTOR)>::type
{ };

}
}
}


    namespace boost {
    namespace di {
    namespace type_traits {

    template<typename T>
    class has_value
    {
        struct base_impl { int value; };
        struct base
            : base_impl
            , mpl::if_<is_class<T>, T, mpl::void_>::type
        { base() { } };

        template<typename U>
        static mpl::aux::no_tag test(
            U*
          , non_type<int base_impl::*, &U::value>* = 0
        );

        static mpl::aux::yes_tag test(...);

    public:
        typedef has_value type;
        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test((base*)(0))) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename>
    struct is_mpl_string
        : mpl::false_
    { };

    template< int C0 , int C1 , int C2 , int C3 , int C4 , int C5 , int C6 , int C7>
    struct is_mpl_string<mpl::string< C0 , C1 , C2 , C3 , C4 , C5 , C6 , C7> >
        : mpl::true_
    { };

    template<typename T>
    struct is_explicit
    {
        BOOST_STATIC_CONSTANT(
            bool
          , value = has_value<T>::value || is_mpl_string<T>::value
        );
    };

    template<typename TExpected, typename TGiven>
    typename disable_if<is_explicit<TGiven>, TExpected*>::type
    create_traits() {
        return new TGiven();
    }

    template<typename TExpected, typename TGiven>
    typename enable_if<has_value<TGiven>, TExpected*>::type
    create_traits() {
        return new TExpected(TGiven::value);
    }

    template<typename TExpected, typename TGiven>
    typename enable_if<is_mpl_string<TGiven>, TExpected*>::type
    create_traits() {
        return new TExpected(mpl::c_str<TGiven>::value);
    }

    template<typename T, typename TObject>
    inline TObject create_impl(TObject object, typename enable_if<is_same<T, detail::any_type> >::type* = 0) {
        return object;
    }

    template<typename T, typename TObject>
    inline T create_impl(TObject object, typename disable_if<is_same<T, detail::any_type> >::type* = 0) {
        return object(type<T>());
    }

    template<typename TExpected, typename TGiven, typename Args0>
    TExpected* create_traits( Args0 args0) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1>
    TExpected* create_traits( Args0 args0 , Args1 args1) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 10>::type>(args10)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 10>::type>(args10) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 11>::type>(args11)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 10>::type>(args10) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 11>::type>(args11) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 12>::type>(args12)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 10>::type>(args10) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 11>::type>(args11) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 12>::type>(args12) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 13>::type>(args13)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 10>::type>(args10) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 11>::type>(args11) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 12>::type>(args12) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 13>::type>(args13) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 14>::type>(args14)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 10>::type>(args10) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 11>::type>(args11) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 12>::type>(args12) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 13>::type>(args13) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 14>::type>(args14) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 15>::type>(args15)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 10>::type>(args10) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 11>::type>(args11) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 12>::type>(args12) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 13>::type>(args13) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 14>::type>(args14) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 15>::type>(args15) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 16>::type>(args16)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 10>::type>(args10) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 11>::type>(args11) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 12>::type>(args12) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 13>::type>(args13) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 14>::type>(args14) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 15>::type>(args15) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 16>::type>(args16) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 17>::type>(args17)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 10>::type>(args10) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 11>::type>(args11) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 12>::type>(args12) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 13>::type>(args13) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 14>::type>(args14) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 15>::type>(args15) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 16>::type>(args16) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 17>::type>(args17) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 18>::type>(args18)

        );
    }

    template<typename TExpected, typename TGiven, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    TExpected* create_traits( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18 , Args19 args19) {
        return new TGiven(
            create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 0>::type>(args0) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 1>::type>(args1) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 2>::type>(args2) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 3>::type>(args3) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 4>::type>(args4) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 5>::type>(args5) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 6>::type>(args6) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 7>::type>(args7) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 8>::type>(args8) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 9>::type>(args9) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 10>::type>(args10) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 11>::type>(args11) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 12>::type>(args12) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 13>::type>(args13) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 14>::type>(args14) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 15>::type>(args15) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 16>::type>(args16) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 17>::type>(args17) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 18>::type>(args18) , create_impl<typename mpl::at_c<typename ctor_traits<TGiven>::type, 19>::type>(args19)

        );
    }

    }
    }
    }

namespace boost {
namespace di {

BOOST_MPL_HAS_XXX_TRAIT_DEF(element_type)

template<
    typename T
  , typename TName = void
  , typename = void
>
class named
{
    typedef typename type_traits::remove_accessors<T>::type object_type;

public:
    typedef T named_type;
    typedef TName name;

    named(const object_type& object)
        : object_(object)
    { }

    operator T() const {
        return object_;
    }

    operator T&() {
        return object_;
    }

private:
    object_type object_;
};

template<
    typename T
  , typename TName
>
class named<T, TName, typename enable_if<
    is_polymorphic<typename type_traits::remove_accessors<T>::type> >::type
>
{
public:
    typedef T named_type;
    typedef TName name;
};

template<
    typename T
  , typename TName
>
class named<T, TName, typename enable_if<
    has_element_type<typename type_traits::remove_accessors<T>::type> >::type
>
{
    typedef typename type_traits::remove_accessors<T>::type object_type;
    typedef typename type_traits::make_plain<T>::type value_type;

public:
    typedef T named_type;
    typedef TName name;

    named() { }

    named(const object_type& object)
        : object_(object)
    { }

    named(typename object_type::element_type* ptr)
        : object_(ptr)
    { }

    named(object_type&& object)
        : object_(std::move(object))
    { }

    operator T() const { return object_; }

    value_type* operator->() const { return object_.get(); }
    value_type& operator*() const { return *object_; }
    value_type* get() const { return object_.get(); }

    void reset() {
        object_.reset();
    }

    void reset(typename object_type::element_type* ptr) {
        object_.reset(ptr);
    }

private:
    object_type object_;
};

}
}

namespace boost {
namespace di {
namespace convertibles {

template<typename T>
class shared
{
public:
    shared() { }

    shared(const aux::shared_ptr<T>& object)
        : object_(object)
    { }

    bool operator!() const {
        return !object_;
    }

    void reset(T* ptr = 0) {
        return object_.reset(ptr);
    }

    template<typename I>
    aux::shared_ptr<I> operator()(const type<aux::shared_ptr<I> >&) const {
        return object_;
    }

    template<typename I>
    aux::shared_ptr<I> operator()(const type<const aux::shared_ptr<I>&>&) const {
        return object_;
    }

    template<typename I, typename TName>
    aux::shared_ptr<I> operator()(const type<named<aux::shared_ptr<I>, TName> >&) const {
        return object_;
    }

    template<typename I, typename TName>
    aux::shared_ptr<I> operator()(const type<named<const aux::shared_ptr<I>&, TName> >&) const {
        return object_;
    }

    template<typename I>
    aux::weak_ptr<I> operator()(const type<aux::weak_ptr<I> >&) const {
        return object_;
    }

    template<typename I>
    aux::weak_ptr<I> operator()(const type<const aux::weak_ptr<I>&>&) const {
        return object_;
    }

    template<typename I, typename TName>
    aux::weak_ptr<I> operator()(const type<named<aux::weak_ptr<I>, TName> >&) const {
        return aux::weak_ptr<I>(object_);
    }

    template<typename I, typename TName>
    aux::weak_ptr<I>
    operator()(const type<named<const aux::weak_ptr<I>&, TName> >&) const {
        return aux::weak_ptr<I>(object_);
    }

    template<typename I>
    operator I() const {
        return (*this)(type<I>());
    }

private:
    aux::shared_ptr<T> object_;
};

}
}
}

namespace boost {
namespace di {
namespace convertibles {

template<typename T>
class copy
{
    typedef function<T*()> object_t;

public:
    template<typename I>
    copy(const I& object)
        : object_(object)
    { }

    template<typename I>
    I operator()(const type<I>&, typename disable_if<is_polymorphic<I> >::type* = 0) const {
        scoped_ptr<I> ptr(object_());
        return *ptr;
    }

    template<typename I>
    const I& operator()(const type<const I&>&) const {
        ref_ = aux::shared_ptr<I>(object_());
        return *ref_;
    }

    template<typename I>
    I* operator()(const type<I*>&) const {
        return object_();
    }

    template<typename I, typename TName>
    I operator()(const type<named<I, TName> >&) const {
        scoped_ptr<I> ptr(object_());
        return *ptr;
    }

    template<typename I>
    aux::shared_ptr<I> operator()(const type<aux::shared_ptr<I> >&) const {
        return aux::shared_ptr<I>(object_());
    }

    template<typename I>
    const aux::shared_ptr<I>& operator()(const type<const aux::shared_ptr<I>&>&) const {
        ref_ = aux::shared_ptr<I>(object_());
        return ref_;
    }

    template<typename I, typename TName>
    I* operator()(const type<named<aux::shared_ptr<I>, TName> >&) const {
        return object_();
    }

    template<typename I>
    aux::auto_ptr<I> operator()(const type<aux::auto_ptr<I> >&) const {
        return aux::auto_ptr<I>(object_());
    }

    template<typename I, typename TName>
    I* operator()(const type<named<aux::auto_ptr<I>, TName> >&) const {
        return object_();
    }

    template<typename I>
    aux::unique_ptr<I> operator()(const type<aux::unique_ptr<I> >&) const {
        return aux::unique_ptr<I>(object_());
    }

    template<typename I, typename TName>
    I* operator()(type<named<aux::unique_ptr<I>, TName> >&) const {
        return object_();
    }

    template<typename I>
    operator I() const {
        return (*this)(type<I>());
    }

private:
    object_t object_;
    mutable aux::shared_ptr<T> ref_;
};

}
}
}

namespace boost {
namespace di {
namespace convertibles {

template<typename T>
class value
{
public:
    value(T value)
        : value_(value)
    { }

    template<typename I>
    I operator()(const type<I>&) const {
        return value_;
    }

    template<typename I>
    I& operator()(const type<I&>&) const {
        return value_;
    }

    template<typename I, typename TName>
    I operator()(const type<named<I, TName>&>&) const {
        return value_;
    }

    template<typename I>
    aux::shared_ptr<I> operator()(const type<aux::shared_ptr<I> >&) {
        return aux::shared_ptr<I>(new I(value_));
    }

    template<typename I>
    const aux::shared_ptr<I>& operator()(const type<const aux::shared_ptr<I>& >&) {
        return aux::shared_ptr<I>(new I(value_));
    }

    template<typename I>
    I* operator()(const type<I*>&) {
        return new I(value_);
    }
    template<typename I>
    operator I() const {
        return (*this)(type<I>());
    }

private:
    mutable T value_;
};

}
}
}

namespace boost {
namespace di {
namespace convertibles {

template<typename T>
class reference
{
public:
    reference(const reference_wrapper<T>& object)
        : object_(object)
    { }

    template<typename I>
    I operator()(const type<I>&) const {
        return object_;
    }

    template<typename I>
    I& operator()(const type<I&>&) const {
        return object_;
    }

    template<typename I, typename TName>
    named<I, TName> operator()(const type<named<I, TName> >&) const {
        return named<I, TName>(object_);
    }

    template<typename I>
    operator I() const {
        return (*this)(type<I>());
    }

private:
    reference_wrapper<T> object_;
};

}
}
}


    namespace boost {
    namespace di {
    namespace scopes {

    template<template<typename> class TConvertible = convertibles::shared>
    class shared
    {
    public:
        typedef mpl::int_<0> priority;

        template<typename TExpected, typename TGiven = TExpected>
        class scope
        {
        public:
            typedef TConvertible<TExpected> result_type;

            result_type create() {
                if (!object_) {
                    object_.reset(type_traits::create_traits<TExpected, TGiven>());
                }
                return object_;
            }

    template< typename Args0>
    result_type create( Args0 args0) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1>
    result_type create( Args0 args0 , Args1 args1) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18 , Args19 args19) {
        if (!object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18 , args19)
            );
        }
        return object_;
    }

        private:
            result_type object_;
        };
    };

    }
    }
    }


    namespace boost {
    namespace di {
    namespace scopes {

    template<typename>
    class callback;

        template<
            typename R
           
           
        >
        class callback0
        {
            typedef R(*f_t)();

        public:

            callback0(
                const f_t& f
               
               
            ) : f(f)
               
               
            { }

            R operator()() const { return f(); }

        private:
            f_t f;

           

        };

        template<
            typename R
            ,
            typename Args0
        >
        class callback1
        {
            typedef R(*f_t)( Args0 );

        public:

            callback1(
                const f_t& f
                ,
                Args0 args0
            ) : f(f)
                ,
                args0(args0)
            { }

            R operator()() const { return f( args0); }

        private:
            f_t f;

            Args0 args0;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1
        >
        class callback2
        {
            typedef R(*f_t)( Args0 , Args1 );

        public:

            callback2(
                const f_t& f
                ,
                Args0 args0 , Args1 args1
            ) : f(f)
                ,
                args0(args0) , args1(args1)
            { }

            R operator()() const { return f( args0 , args1); }

        private:
            f_t f;

            Args0 args0; Args1 args1;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2
        >
        class callback3
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 );

        public:

            callback3(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2)
            { }

            R operator()() const { return f( args0 , args1 , args2); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3
        >
        class callback4
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 );

        public:

            callback4(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4
        >
        class callback5
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 );

        public:

            callback5(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5
        >
        class callback6
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 );

        public:

            callback6(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6
        >
        class callback7
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 );

        public:

            callback7(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7
        >
        class callback8
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 );

        public:

            callback8(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8
        >
        class callback9
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 );

        public:

            callback9(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9
        >
        class callback10
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 );

        public:

            callback10(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10
        >
        class callback11
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 );

        public:

            callback11(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9) , args10(args10)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9; Args10 args10;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11
        >
        class callback12
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 );

        public:

            callback12(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9) , args10(args10) , args11(args11)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9; Args10 args10; Args11 args11;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12
        >
        class callback13
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 );

        public:

            callback13(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9) , args10(args10) , args11(args11) , args12(args12)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9; Args10 args10; Args11 args11; Args12 args12;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13
        >
        class callback14
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 );

        public:

            callback14(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9) , args10(args10) , args11(args11) , args12(args12) , args13(args13)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9; Args10 args10; Args11 args11; Args12 args12; Args13 args13;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14
        >
        class callback15
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 );

        public:

            callback15(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9) , args10(args10) , args11(args11) , args12(args12) , args13(args13) , args14(args14)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9; Args10 args10; Args11 args11; Args12 args12; Args13 args13; Args14 args14;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15
        >
        class callback16
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 );

        public:

            callback16(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9) , args10(args10) , args11(args11) , args12(args12) , args13(args13) , args14(args14) , args15(args15)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9; Args10 args10; Args11 args11; Args12 args12; Args13 args13; Args14 args14; Args15 args15;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16
        >
        class callback17
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 );

        public:

            callback17(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9) , args10(args10) , args11(args11) , args12(args12) , args13(args13) , args14(args14) , args15(args15) , args16(args16)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9; Args10 args10; Args11 args11; Args12 args12; Args13 args13; Args14 args14; Args15 args15; Args16 args16;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17
        >
        class callback18
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 );

        public:

            callback18(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9) , args10(args10) , args11(args11) , args12(args12) , args13(args13) , args14(args14) , args15(args15) , args16(args16) , args17(args17)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9; Args10 args10; Args11 args11; Args12 args12; Args13 args13; Args14 args14; Args15 args15; Args16 args16; Args17 args17;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18
        >
        class callback19
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 );

        public:

            callback19(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9) , args10(args10) , args11(args11) , args12(args12) , args13(args13) , args14(args14) , args15(args15) , args16(args16) , args17(args17) , args18(args18)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9; Args10 args10; Args11 args11; Args12 args12; Args13 args13; Args14 args14; Args15 args15; Args16 args16; Args17 args17; Args18 args18;

        };

        template<
            typename R
            ,
            typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19
        >
        class callback20
        {
            typedef R(*f_t)( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19 );

        public:

            callback20(
                const f_t& f
                ,
                Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18 , Args19 args19
            ) : f(f)
                ,
                args0(args0) , args1(args1) , args2(args2) , args3(args3) , args4(args4) , args5(args5) , args6(args6) , args7(args7) , args8(args8) , args9(args9) , args10(args10) , args11(args11) , args12(args12) , args13(args13) , args14(args14) , args15(args15) , args16(args16) , args17(args17) , args18(args18) , args19(args19)
            { }

            R operator()() const { return f( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18 , args19); }

        private:
            f_t f;

            Args0 args0; Args1 args1; Args2 args2; Args3 args3; Args4 args4; Args5 args5; Args6 args6; Args7 args7; Args8 args8; Args9 args9; Args10 args10; Args11 args11; Args12 args12; Args13 args13; Args14 args14; Args15 args15; Args16 args16; Args17 args17; Args18 args18; Args19 args19;

        };

    template<template<typename> class TConvertible = convertibles::copy>
    class unique
    {
    public:
        typedef mpl::int_<0> priority;

        template<typename TExpected, typename TGiven = TExpected>
        class scope
        {
        public:
            typedef TConvertible<TExpected> result_type;

            result_type create() {
                return callback0<TExpected*>(
                    &type_traits::create_traits<TExpected, TGiven>
                );
            }

        template< typename Args0>
        result_type create( Args0 args0) {
            return callback1<TExpected*, Args0>(
                &type_traits::create_traits<TExpected, TGiven, Args0>
              , args0
            );
        }

        template< typename Args0 , typename Args1>
        result_type create( Args0 args0 , Args1 args1) {
            return callback2<TExpected*, Args0 , Args1>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1>
              , args0 , args1
            );
        }

        template< typename Args0 , typename Args1 , typename Args2>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2) {
            return callback3<TExpected*, Args0 , Args1 , Args2>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2>
              , args0 , args1 , args2
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3) {
            return callback4<TExpected*, Args0 , Args1 , Args2 , Args3>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3>
              , args0 , args1 , args2 , args3
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4) {
            return callback5<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4>
              , args0 , args1 , args2 , args3 , args4
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5) {
            return callback6<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5>
              , args0 , args1 , args2 , args3 , args4 , args5
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6) {
            return callback7<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7) {
            return callback8<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8) {
            return callback9<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9) {
            return callback10<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10) {
            return callback11<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11) {
            return callback12<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12) {
            return callback13<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13) {
            return callback14<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14) {
            return callback15<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15) {
            return callback16<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16) {
            return callback17<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17) {
            return callback18<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18) {
            return callback19<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18
            );
        }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
        result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18 , Args19 args19) {
            return callback20<TExpected*, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19>(
                &type_traits::create_traits<TExpected, TGiven, Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19>
              , args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18 , args19
            );
        }
        };
    };

    }
    }
    }

namespace boost {
namespace di {
namespace scopes {

class deduce
{
public:
    typedef mpl::int_<0> priority;

    template<typename, typename>
    struct scope
    {
        typedef none_t result_type;
    };
};

}
}
}


    namespace boost {
    namespace di {

    template<typename T>
    class has_call_operator
    {
        struct base_impl { void operator()(...) { } };
        struct base
            : base_impl
            , mpl::if_<is_class<T>, T, mpl::void_>::type
        { base() { } };

        template<typename U>
        static mpl::aux::no_tag test(
            U*
          , non_type<void (base_impl::*)(...), &U::operator()>* = 0
        );

        static mpl::aux::yes_tag test(...);

    public:
        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test((base*)(0))) == sizeof(mpl::aux::yes_tag)
        );
    };

    namespace scopes {

    template<template<typename> class TConvertible = convertibles::value>
    class external
    {
    public:
        typedef mpl::int_<1> priority;

        template<typename TExpected, typename = TExpected>
        class scope
        {
        public:
            typedef TConvertible<TExpected> result_type;

        private:
            class callback
            {
            public:
                template<typename T>
                explicit callback(const T& object)
                    : object_(object)
                { }

                result_type operator()() const {
                    return object_;
                }

            private:
                result_type object_;
            };

        public:
            template<typename T>
            explicit scope(const T& object, typename enable_if_c<has_call_operator<T>::value>::type* = 0)
                : object_(object)
            { }

            template<typename T>
            explicit scope(const T& object, typename disable_if_c<has_call_operator<T>::value>::type* = 0)
                : object_(callback(object))
            { }

            result_type create() {
                return object_();
            }

    template< typename Args0>
    result_type create( Args0 ) {
        return object_();
    }

    template< typename Args0 , typename Args1>
    result_type create( Args0 , Args1 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2>
    result_type create( Args0 , Args1 , Args2 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3>
    result_type create( Args0 , Args1 , Args2 , Args3 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 ) {
        return object_();
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    result_type create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19 ) {
        return object_();
    }

        private:
            function<result_type()> object_;
        };
    };

    }
    }
    }


    namespace boost {
    namespace di {
    namespace scopes {

    class session_entry { };
    class session_exit { };

    template<template<typename> class TConvertible = convertibles::shared>
    class session
    {
    public:
        typedef mpl::int_<0> priority;

        template<typename TExpected, typename TGiven = TExpected>
        class scope
        {
        public:
            typedef TConvertible<TExpected> result_type;

            scope()
                : in_scope_(false)
            { }

            void call(const session_entry&) {
                in_scope_ = true;
            }

            void call(const session_exit&) {
                in_scope_ = false;
                object_.reset();
            }

            result_type create() {
                if (in_scope_ && !object_) {
                    object_.reset(type_traits::create_traits<TExpected, TGiven>());
                }
                return object_;
            }

    template< typename Args0>
    result_type create( Args0 args0) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1>
    result_type create( Args0 args0 , Args1 args1) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18)
            );
        }
        return object_;
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    result_type create( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18 , Args19 args19) {
        if (in_scope_ && !object_) {
            object_.reset(
                type_traits::create_traits<TExpected, TGiven>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18 , args19)
            );
        }
        return object_;
    }

        private:
            result_type object_;
            bool in_scope_;
        };
    };

    }
    }
    }

namespace boost {
namespace di {
namespace type_traits {

template<typename T, typename = void>
struct scope_traits
{
    typedef scopes::unique<> type;
};

template<typename T>
struct scope_traits<T&>
{
    typedef scopes::external<> type;
};

template<typename T>
struct scope_traits<const T&>
{
    typedef scopes::unique<> type;
};

template<typename T>
struct scope_traits<T*>
{
    typedef scopes::unique<> type;
};

template<typename T>
struct scope_traits<const T*>
{
    typedef scopes::unique<> type;
};

template<typename T>
struct scope_traits<aux::auto_ptr<T> >
{
    typedef scopes::unique<> type;
};

template<typename T>
struct scope_traits<aux::shared_ptr<T> >
{
    typedef scopes::shared<> type;
};

template<typename T>
struct scope_traits<aux::weak_ptr<T> >
{
    typedef scopes::shared<> type;
};

template<typename T>
struct scope_traits<aux::unique_ptr<T> >
{
    typedef scopes::unique<> type;
};

template<typename T>
struct scope_traits<T&&>
{
    typedef scopes::unique<> type;
};

template<typename T>
struct scope_traits<const T&&>
{
    typedef scopes::unique<> type;
};

template<typename T>
struct scope_traits<T, typename enable_if<has_named_type<T> >::type>
{
    typedef typename scope_traits<typename T::named_type>::type type;
};

}
}
}

namespace boost {
namespace di {
namespace concepts {
namespace type_traits {

template<typename T, typename U = mpl::_1>
struct is_req_type
    : mpl::or_<
          is_base_of<typename di::type_traits::make_plain<U>::type, T>
        , is_same<typename di::type_traits::make_plain<U>::type, T>
      >
{ };

}
}
}
}

namespace boost {
namespace di {
namespace concepts {
namespace type_traits {

BOOST_MPL_HAS_XXX_TRAIT_DEF(name)

template<typename T, typename, typename = void>
struct is_req_name_impl
    : mpl::false_
{ };

template<typename T, typename TName>
struct is_req_name_impl<T, TName, typename enable_if<has_name<T> >::type>
    : is_same<typename T::name, TName>
{ };

template<typename TName, typename T = mpl::_1>
struct is_req_name
    : mpl::times<mpl::int_<5>,
     is_req_name_impl<
          typename di::type_traits::remove_accessors<T>::type
        , TName
      >
      >
{ };

}
}
}
}

namespace boost {
namespace di {
namespace concepts {
namespace type_traits {

template<typename TContext, typename TCallStack>
struct equal_call_stack
    : mpl::equal<
          mpl::iterator_range<
              typename mpl::advance<
                  typename mpl::begin<TCallStack>::type
                , typename mpl::max<
                      mpl::int_<0>
                    , mpl::minus<
                          mpl::size<TCallStack>
                        , mpl::size<TContext>
                      >
                  >::type
              >::type
            , typename mpl::end<TCallStack>::type
          >
        , TContext
      >
{ };

template<typename TContext, typename TCallStack>
struct get_longest_call_stack_size
    : mpl::fold<
          TContext
        , mpl::int_<0>
        , mpl::if_<
             equal_call_stack<mpl::_2, TCallStack>
            , mpl::size<mpl::_2>
            , mpl::_1
          >
      >::type
{ };

template<typename TContext, typename TCallStack = mpl::_2>
struct is_req_call
    : mpl::if_<
            mpl::empty<TContext>
        , mpl::int_<1>
         , mpl::times<mpl::int_<10>, get_longest_call_stack_size<TContext, TCallStack> >
      >::type
{ };

}
}
}
}

namespace boost {
namespace di {
namespace concepts {
namespace type_traits {

template<typename TScope = mpl::_3>
struct priority
    : mpl::times<
          mpl::int_<100>
        , mpl::plus<
              mpl::int_<1>
            , typename TScope::priority
          >
      >
{ };

}
}
}
}


namespace boost {
namespace di {
namespace concepts {

template<
    typename TExpected
  , typename TGiven
  , template<
        typename
      , typename
      , typename
      , typename
    > class TDependency
>
struct bind
    : TDependency<
          mpl::_1
        , TExpected
        , TGiven
        , typename mpl::lambda<
              mpl::times<
                  type_traits::priority<>
                , type_traits::is_req_type<TExpected>
              >
          >::type
      >
{
    template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
    struct when
        : TDependency<
              mpl::_1
            , TExpected
            , TGiven
            , typename mpl::lambda<
                  mpl::times<
                      type_traits::priority<>
                    , type_traits::is_req_type<TExpected>
                    , type_traits::is_req_call<mpl::vector< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19> >
                  >
              >::type
          >
    {
        template<typename TName>
        struct named
            : TDependency<
                  mpl::_1
                , TExpected
                , TGiven
                , typename mpl::lambda<
                      mpl::times<
                          type_traits::priority<>
                        , type_traits::is_req_type<TExpected>
                        , type_traits::is_req_name<TName>
                        , type_traits::is_req_call<mpl::vector< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19> >
                      >
                >::type
              >
        { };
    };

    template<typename TName>
    struct named
        : TDependency<
              mpl::_1
            , TExpected
            , TGiven
            , typename mpl::lambda<
                  mpl::times<
                      type_traits::priority<>
                    , type_traits::is_req_type<TExpected>
                    , type_traits::is_req_name<TName>
                  >
            >::type
          >
    {
        template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
        struct when
            : TDependency<
                  mpl::_1
                , TExpected
                , TGiven
                , typename mpl::lambda<
                      mpl::times<
                          type_traits::priority<>
                        , type_traits::is_req_type<TExpected>
                        , type_traits::is_req_name<TName>
                        , type_traits::is_req_call<mpl::vector< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19> >
                      >
                >::type
              >
        { };
    };
};

}
}
}


namespace boost {
namespace di {
namespace concepts {

template<
    typename TScope
  , template<
        typename
      , typename
      , typename
      , typename
    > class TDependency
>
class scope
{
    BOOST_MPL_HAS_XXX_TRAIT_DEF(bind)

    template<typename T>
    struct is_dependency
        : has_bind<T>
    { };

    template<typename T>
    struct dependency
        : TDependency<
              mpl::_1
            , T
            , T
            , typename mpl::lambda<
                  mpl::times<
                      type_traits::priority<>
                    , type_traits::is_req_type<T>
                  >
              >::type
          >
    { };

    template<typename T, typename U>
    struct rebind
        : T::template rebind<U>::other
    { };

public:
    template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
    struct bind
        : mpl::fold<
              mpl::vector< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19>
            , mpl::vector0<>
            , mpl::push_back<
                  mpl::_1
                , mpl::if_<
                      is_dependency<mpl::_2>
                    , rebind<mpl::_2, TScope>
                    , rebind<dependency<mpl::_2>, TScope>
                  >
              >
          >::type
    { };
};

}
}
}

namespace boost {
namespace di {
namespace concepts {

namespace detail {

template<typename T>
struct scope_traits
{
    typedef T type;
};

template<>
struct scope_traits<mpl::_1>
{
    typedef scopes::deduce type;
};

}

template<
    typename TExpected
  , typename TGiven
  , typename TScope
>
struct get_scope
{
    typedef typename detail::scope_traits<TScope>::type::
        template scope<TExpected, TGiven> type;
};

template<
    typename TScope
  , typename TExpected
  , typename TGiven = TExpected
  , typename TBind = typename mpl::lambda<
        mpl::times<
            concepts::type_traits::priority<>
          , concepts::type_traits::is_req_type<TExpected>
        >
    >::type
>
class dependency : public get_scope<TExpected, TGiven, TScope>::type
{
    typedef typename get_scope<TExpected, TGiven, TScope>::type scope_type;
    typedef scopes::external<convertibles::reference> ref_type;
    typedef scopes::external<convertibles::shared> shared_type;
    typedef scopes::external<convertibles::value> value_type;

    template<typename T, typename U, typename S>
    struct external
    {
        typedef dependency<S, T, U, TBind> type;
    };

    template<typename T>
    class has_call_operator
    {
        struct base_impl { void operator()(...) { } };
        struct base
            : base_impl
            , mpl::if_<is_class<T>, T, mpl::void_>::type
        { base() { } };

        template<typename U>
        static mpl::aux::no_tag test(
            U*
          , non_type<void (base_impl::*)(...), &U::operator()>* = 0
        );

        static mpl::aux::yes_tag test(...);

    public:
        typedef has_call_operator type;

        BOOST_STATIC_CONSTANT(
            bool
          , value = sizeof(test((base*)(0))) == sizeof(mpl::aux::yes_tag)
        );
    };

    template<typename, typename = void>
    struct is_text
        : mpl::false_
    { };

    template<typename T, int N>
    struct is_text<T[N], void>
        : mpl::true_
    { };

    template<typename T>
    struct is_text<std::string, T>
        : mpl::true_
    { };

    template<typename T>
    struct is_text<const char*, T>
        : mpl::true_
    { };

    template<typename T>
    struct is_text<char*, T>
        : mpl::true_
    { };

    template<typename T>
    struct is_value
        : mpl::or_<is_arithmetic<T>, is_enum<T>, is_text<T> >
    { };

    template<typename T>
    struct get_convertible_impl;

    template<typename T>
    struct get_convertible_impl<T&>
    {
        typedef ref_type type;
    };

    template<typename T>
    struct get_convertible_impl<aux::shared_ptr<T> >
    {
        typedef shared_type type;
    };

    template<typename T, typename = void>
    struct get_convertible
    {
        typedef T type;
    };

    template<typename T>
    struct get_convertible<T, typename enable_if<has_call_operator<T> >::type>
        : get_convertible_impl<typename di::type_traits::parameter_types<BOOST_TYPEOF_TPL(&T::operator())>::result_type>
    { };

public:
    typedef dependency type;
    typedef typename detail::scope_traits<TScope>::type scope;
    typedef TExpected expected;
    typedef TGiven given;
    typedef TBind bind;

    template<typename T>
    struct rebind
    {
        typedef dependency<
            typename mpl::if_<
                is_same<scope, scopes::deduce>
              , T
              , TScope
            >::type
          , TExpected
          , TGiven
          , TBind
        > other;
    };

    dependency() { }

    template<typename T>
    explicit dependency(const T& obj)
        : scope_type(obj)
    { }

    template<typename T>
    static typename external<expected, T, value_type>::type
    to(const T& obj, typename enable_if<is_value<T> >::type* = 0
                   , typename disable_if<has_call_operator<T> >::type* = 0) {
        return typename external<expected, T, value_type>::type(obj);
    }

    template<typename T>
    static typename external<const expected, T, ref_type>::type
    to(const T& obj, typename disable_if<is_value<T> >::type* = 0
                   , typename disable_if<has_call_operator<T> >::type* = 0) {
        return typename external<const expected, T, ref_type>::type(boost::cref(obj));
    }

    template<typename T>
    static typename external<expected, T, typename get_convertible<T>::type>::type
    to(const T& obj, typename enable_if<has_call_operator<T> >::type* = 0
                   , typename disable_if<is_value<T> >::type* = 0) {
        return typename external<expected, T, typename get_convertible<T>::type>::type(obj);
    }

    template<typename T>
    static typename external<expected, T, ref_type>::type
    to(T& obj) {
        return typename external<expected, T, ref_type>::type(boost::ref(obj));
    }

    template<typename T>
    static typename external<expected, T, shared_type>::type
    to(aux::shared_ptr<T> obj) {
        return typename external<expected, T, shared_type>::type(obj);
    }
};

}
}
}

namespace boost {
namespace di {
namespace detail {

template<typename TDeps = mpl::vector0<> >
class binder
{
    template<typename TDependency, typename T, typename TCallStack>
    struct comparator
        : mpl::apply<
              typename TDependency::bind
            , T
            , TCallStack
            , typename TDependency::scope
          >::type
    { };

public:
    template<
        typename T
      , typename TCallStack
      , typename TDefault =
            ::boost::di::concepts::dependency<
                typename type_traits::scope_traits<T>::type
              , typename type_traits::make_plain<T>::type
            >
    >
    struct resolve
        : mpl::deref<
              mpl::second<
                  typename mpl::fold<
                      TDeps
                    , mpl::pair<mpl::int_<0>, TDefault>
                    , mpl::if_<
                          mpl::greater<
                              comparator<
                                  mpl::_2
                                , T
                                , TCallStack
                              >
                            , mpl::first<mpl::_1>
                          >
                        , mpl::pair<comparator<mpl::_2, T, TCallStack>, mpl::_2>
                        , mpl::_1
                      >
                  >::type
              >
          >::type::template rebind<
              typename type_traits::scope_traits<T>::type
          >::other
    { };
};

}
}
}


namespace boost {
namespace di {
namespace policies {

BOOST_MPL_HAS_XXX_TRAIT_DEF(element_type)
BOOST_MPL_HAS_XXX_TRAIT_DEF(value_type)

struct allow_smart_ptrs
{
    template<typename, typename = void>
    struct allow
        : mpl::false_
    { };

    template<typename T>
    struct allow<T, typename enable_if<has_element_type<T> >::type>
        : mpl::true_
    { };
};

struct allow_refs
{
    template<typename T>
    struct allow
        : is_reference<T>
    { };
};

struct allow_const_refs
{
    template<typename T>
    struct allow
        : mpl::and_<
              is_const<typename remove_reference<T>::type>
            , is_reference<T>
          >
    { };
};

struct allow_rvalue_refs
{
    template<typename T>
    struct allow
        : is_rvalue_reference<T>
    { };
};

struct allow_ptrs
{
    template<typename T>
    struct allow
        : is_pointer<T>
    { };
};

struct allow_copies
{
    template<typename T>
    struct allow
        : mpl::and_<
               mpl::not_<is_reference<T> >
             , mpl::not_<is_pointer<T> >
             , mpl::not_<is_rvalue_reference<T> >
             , mpl::not_<has_element_type<T> >
          >
    { };
};

namespace detail {

template<typename T>
struct value_type
{
    typedef typename T::value_type type;
};

template<typename TAllow, typename T>
struct is_allowed_impl
    : TAllow::template allow<T>
{ };

template<typename, typename, typename = void>
struct is_allowed_nested_impl
    : mpl::true_
{ };

template<typename TAllow, typename T>
struct is_allowed_nested_impl<TAllow, T, typename enable_if<has_value_type<T> >::type>
    : TAllow::template allow<typename value_type<T>::type>
{ };

}
template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
class arguments_permission
{
    typedef mpl::vector< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19> allows_type;

    template<typename T>
    struct is_allowed_nested
        : mpl::bool_<
              mpl::count_if<
                  allows_type
                , detail::is_allowed_nested_impl<
                      mpl::_
                    , typename type_traits::remove_accessors<T>::type
                  >
              >::value != 0
          >
    { };

    template<typename T>
    struct is_allowed
        : mpl::bool_<
              mpl::count_if<
                  allows_type
                , mpl::and_<
                      detail::is_allowed_impl<mpl::_, T>
                    , is_allowed_nested<T>
                  >
              >::value != 0
          >
    { };

public:
    template<
        typename TDeps
      , typename T
    >
    static void assert_policy() {
        BOOST_MPL_ASSERT_MSG(is_allowed<typename T::type>::value, ARGUMENT_NOT_PERMITTED, (typename T::type))

         ;
    }
};

}
}
}


namespace boost {
namespace di {
namespace policies {

class creation_ownership
{
public:
    template<
        typename
      , typename T
    >
    static typename disable_if<is_reference<typename T::type> >::type assert_policy() { }

    template<
        typename
      , typename T
    >
    static typename enable_if<is_reference<typename T::type> >::type assert_policy() {
        BOOST_MPL_ASSERT_MSG(false, CREATION_OWNERSHIP_IS_NOT_CLEAR, (typename T::type))

         ;
    }
};

}
}
}

namespace boost {
namespace di {
namespace policies {
class binding_correctness
{
    template<typename>
    struct is_scope
        : mpl::false_
    { };

    template<template<typename> class TConvertible>
    struct is_scope<scopes::shared<TConvertible> >
        : mpl::true_
    { };

    template<template<typename> class TConvertible>
    struct is_scope<scopes::session<TConvertible> >
        : mpl::true_
    { };

    template<typename T>
    struct scope_
    {
        typedef typename T::scope type;
    };

    template<typename T>
    struct expected
    {
        typedef typename T::expected type;
    };

    template<typename T>
    struct context
    {
        typedef typename T::context type;
    };

    template<typename T, typename = void>
    struct get_type
    {
        typedef T type;
    };

    template<typename T>
    struct get_type<T, typename enable_if<mpl::is_sequence<T> >::type>
    {
        typedef typename mpl::back<T>::type type;
    };

    template<typename T>
    struct ctor
        : type_traits::ctor_traits<
              typename type_traits::make_plain<T>::type
          >::type
    { };

    template<
        typename T
      , typename TCallStack
      , typename TBind
    >
    struct binder
        : TBind::template get_dependency<T, TCallStack>::type
    { };

    template<
        typename T
      , typename TBind
      , typename TCallStack =
            mpl::vector1<typename type_traits::make_plain<T>::type>
    >
    struct deps_
        : mpl::fold<
              ctor<typename binder<T, TCallStack, TBind>::given>
            , mpl::vector0<>
            , mpl::copy<
                  mpl::joint_view<
                      mpl::vector1<binder<mpl::_2, TCallStack, TBind> >
                    , deps_<
                          mpl::_2
                        , TBind
                        , mpl::push_back<
                              TCallStack
                            , type_traits::make_plain<mpl::_2>
                          >
                      >
                  >
                , mpl::back_inserter<mpl::_1>
              >
          >
    { };

    template<typename TDeps>
    struct get_singletons
        : mpl::fold<
              TDeps
            , mpl::vector0<>
            , mpl::if_<
                  is_scope<scope_<mpl::_2> >
                , mpl::push_back<mpl::_1, expected<mpl::_2> >
                , mpl::_1
              >
          >
    { };

    template<typename TDeps, typename T>
    struct is_in_any_context
        : mpl::contains<
              typename mpl::fold<
                  typename mpl::fold<
                      typename mpl::transform<TDeps, context<mpl::_> >::type
                    , mpl::vector0<>
                    , mpl::copy<
                          mpl::_2
                        , mpl::back_inserter<mpl::_1>
                      >
                  >::type
                , mpl::vector0<>
                , mpl::push_back<mpl::_1, get_type<mpl::_2> >
              >::type
            , T
          >
    { };

    template<typename TDeps>
    struct undefined_behavior_impl
        : mpl::fold<
              typename mpl::fold<
                  typename get_singletons<TDeps>::type
                , mpl::set0<>
                , mpl::if_<
                      is_in_any_context<TDeps, mpl::_2>
                    , mpl::insert<mpl::_1, mpl::_2>
                    , mpl::_1
                  >
              >::type
            , mpl::vector0<>
            , mpl::push_back<mpl::_1, mpl::_2>
          >
    { };

    template<typename TBind, typename T, typename TName>
    struct comparator
        : mpl::apply<TBind, T, TName>::type
    { };

    template<
        typename TCtor
      , typename TDependency
    >
    struct ctor_has_type
        : mpl::count_if<
              TCtor
            , comparator<
                  typename TDependency::bind
                , mpl::_1
                , typename TDependency::name
              >
          >::type
    { };

    template<typename T>
    struct get_context
        : mpl::fold<
              typename T::context
            , mpl::vector0<>
            , mpl::if_<
                  mpl::is_sequence<mpl::_2>
                , mpl::push_back<
                      mpl::_1
                    , mpl::back<mpl::_2>
                  >
                , mpl::push_back<mpl::_1, mpl::_2>
              >
          >::type
    { };

    template<typename TDependency, typename TResult>
    struct for_each_context
        : mpl::fold<
              get_context<TDependency>
            , TResult
            , mpl::if_<
                 ctor_has_type<
                      ctor<mpl::_2>
                    , TDependency
                  >
                , mpl::_1
                , mpl::push_back<
                      mpl::_1
                    , mpl::pair<
                          typename expected<TDependency>::type
                        , mpl::_2
                      >
                  >
              >
          >::type
    { };

    template<typename TDeps>
    struct binding_impl
        : mpl::fold<
              TDeps
            , mpl::vector0<>
            , for_each_context<mpl::_2, mpl::_1>
          >::type
    { };

    template<
        typename TDeps
      , typename TAssert
      , typename T = typename binding_impl<TDeps>::type
    >
    struct binding : T
    {
       BOOST_MPL_ASSERT_MSG(
            !TAssert::value || mpl::empty<T>::value
          , BINDING_DECLARATION_IS_NOT_CORRECT
          , (T)
        );
    };

    template<
        typename TDeps
      , typename TGiven
      , typename TBinder
      , typename TAssert
      , typename T = typename undefined_behavior_impl<
            typename deps_<TGiven, TBinder>::type
        >::type
    >
    struct undefined_behavior : T
    {
        BOOST_MPL_ASSERT_MSG(
            !TAssert::value || mpl::empty<T>::value
          , ARGUMENTS_EVALUTION_ORDER_UNDEFINED_BEHAVIOR
          , (T)
        );
    };

public:
    template<
        typename TDeps
      , typename TGiven
      , typename TAssert = mpl::true_
      , template<typename> class TBinder = di::detail::binder
    >
    struct verify
        : mpl::joint_view<
              binding<TDeps, TAssert>
            , undefined_behavior<TDeps, TGiven, TBinder<TDeps>, TAssert>
          >
    { };

    template<
        typename TDeps
      , typename T
    >
    static void assert_policy() { }
};

}
}
}


namespace boost {
namespace di {
namespace policies {
class circular_dependencies
{
    template<typename TCallStack>
    struct is_unique_call_stack
        : mpl::bool_<
              static_cast<std::size_t>(mpl::accumulate<
                  typename mpl::transform<
                      TCallStack
                    , mpl::count<TCallStack, mpl::_>
                  >::type
                , mpl::int_<0>
                , mpl::plus<mpl::_1, mpl::_2>
              >::type::value
            ) == mpl::size<TCallStack>::value
          >
    { };

public:
    template<
        typename
      , typename T
    >
    static void assert_policy() {
       BOOST_MPL_ASSERT_MSG(is_unique_call_stack<typename T::call_stack>::value, CIRCULAR_DEPENDENCIES_ARE_NOT_ALLOWED, (typename T::call_stack))

         ;
    }
};

}
}
}


namespace boost {
namespace di {
namespace policies {

template<typename TScope>
struct allow_scope
{
    template<typename T>
    struct allow
        : is_same<T, TScope>
    { };
};
template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
class scopes_permission
{
    template<
        typename T
      , typename TCallStackSize
      , typename TCtor =
            typename type_traits::ctor_traits<
                typename type_traits::make_plain<T>::type
            >::type
    >
    struct ctor
        : mpl::if_<
              mpl::and_<
                  mpl::empty<TCtor>
                , mpl::equal_to<TCallStackSize, mpl::int_<1> >
              >
            , mpl::vector1<T>
            , TCtor
          >::type
    { };

    template<
        typename T
      , typename TCallStack
      , typename TBind
    >
    struct binder
        : TBind::template get_dependency<T, TCallStack>::type
    { };

    template<typename TAllow, typename T>
    struct is_allowed_impl
        : TAllow::template allow<T>
    { };

    template<
        typename T
      , typename TAllows = mpl::vector< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19>
    >
    struct is_allowed
        : mpl::bool_<
              mpl::count_if<
                  TAllows
                , is_allowed_impl<mpl::_, T>
              >::value != 0
          >
    { };

    template<typename T>
    struct scope
    {
        typedef typename T::scope type;
    };

    template<
        typename T
      , typename TBind
      , typename TCallStack =
            mpl::vector1<typename type_traits::make_plain<T>::type>
    >
    struct scopes_permission_impl
        : mpl::fold<
              ctor<typename binder<T, TCallStack, TBind>::given, mpl::size<TCallStack> >
            , mpl::vector0<>
            , mpl::copy<
                  mpl::joint_view<
                      mpl::if_<
                          is_allowed<
                              scope<binder<mpl::_2, TCallStack, TBind> >
                          >
                        , mpl::_2
                        , mpl::vector1<
                              mpl::pair<
                                  mpl::_2
                                , scope<binder<mpl::_2, TCallStack, TBind> >
                              >
                          >
                      >
                    , scopes_permission_impl<
                          mpl::_2
                        , TBind
                        , mpl::push_back<
                              TCallStack
                            , type_traits::make_plain<mpl::_2>
                          >
                      >
                  >
                , mpl::back_inserter<mpl::_1>
              >
          >
    { };

    template<typename T, typename TAssert>
    struct verify_impl : T
    {
        BOOST_MPL_ASSERT_MSG(
            !TAssert::value || mpl::empty<T>::value
          , SCOPE_NOT_PERMITTED
          , (T)
        );
    };

public:
    template<
        typename TDeps
      , typename TGiven
      , typename TAssert = mpl::true_
      , template<typename> class TBinder = di::detail::binder
    >
    struct verify
        : verify_impl<
              typename scopes_permission_impl<TGiven, TBinder<TDeps> >::type
            , TAssert
          >
    { };

    template<
        typename TDeps
      , typename T
    >
    static void assert_policy() { }
};

}
}
}


    namespace boost {
    namespace di {
    namespace detail {

    BOOST_MPL_HAS_XXX_TRAIT_DEF(types)

    class init { };

    template<typename T>
    struct never
        : mpl::false_
    { };

    template<
        typename TSeq = mpl::vector0<>
      , typename TIgnore = never<mpl::_1>
      , typename = void
    >
    class pool
    {
    public:
        typedef pool type;
        typedef TSeq types;

        pool() { }

        template<typename T>
        explicit pool(const pool<T>&, const init&)
        { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 1>::type>
        : public mpl::at_c<TSeq, 0>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 2>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 3>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 4>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 5>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 6>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 7>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 8>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 9>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 10>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 11>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type , public mpl::at_c<TSeq, 10>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 11 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 12>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type , public mpl::at_c<TSeq, 10>::type , public mpl::at_c<TSeq, 11>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 11 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 12 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 13>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type , public mpl::at_c<TSeq, 10>::type , public mpl::at_c<TSeq, 11>::type , public mpl::at_c<TSeq, 12>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 11 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 12 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 13 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 14>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type , public mpl::at_c<TSeq, 10>::type , public mpl::at_c<TSeq, 11>::type , public mpl::at_c<TSeq, 12>::type , public mpl::at_c<TSeq, 13>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 11 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 12 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 13 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 14 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 15>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type , public mpl::at_c<TSeq, 10>::type , public mpl::at_c<TSeq, 11>::type , public mpl::at_c<TSeq, 12>::type , public mpl::at_c<TSeq, 13>::type , public mpl::at_c<TSeq, 14>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 11 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 12 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 13 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 14 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 15 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 16>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type , public mpl::at_c<TSeq, 10>::type , public mpl::at_c<TSeq, 11>::type , public mpl::at_c<TSeq, 12>::type , public mpl::at_c<TSeq, 13>::type , public mpl::at_c<TSeq, 14>::type , public mpl::at_c<TSeq, 15>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 11 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 12 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 13 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 14 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 15 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 16 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 17>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type , public mpl::at_c<TSeq, 10>::type , public mpl::at_c<TSeq, 11>::type , public mpl::at_c<TSeq, 12>::type , public mpl::at_c<TSeq, 13>::type , public mpl::at_c<TSeq, 14>::type , public mpl::at_c<TSeq, 15>::type , public mpl::at_c<TSeq, 16>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15 , const Args16 &args16) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) , Args16(args16) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 11 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 12 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 13 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 14 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 15 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 16 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 17 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 16>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 16 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 18>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type , public mpl::at_c<TSeq, 10>::type , public mpl::at_c<TSeq, 11>::type , public mpl::at_c<TSeq, 12>::type , public mpl::at_c<TSeq, 13>::type , public mpl::at_c<TSeq, 14>::type , public mpl::at_c<TSeq, 15>::type , public mpl::at_c<TSeq, 16>::type , public mpl::at_c<TSeq, 17>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15 , const Args16 &args16) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) , Args16(args16) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15 , const Args16 &args16 , const Args17 &args17) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) , Args16(args16) , Args17(args17) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 11 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 12 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 13 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 14 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 15 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 16 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 17 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 16>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 16 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 18 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 16>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 16 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 17>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 17 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 19>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type , public mpl::at_c<TSeq, 10>::type , public mpl::at_c<TSeq, 11>::type , public mpl::at_c<TSeq, 12>::type , public mpl::at_c<TSeq, 13>::type , public mpl::at_c<TSeq, 14>::type , public mpl::at_c<TSeq, 15>::type , public mpl::at_c<TSeq, 16>::type , public mpl::at_c<TSeq, 17>::type , public mpl::at_c<TSeq, 18>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15 , const Args16 &args16) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) , Args16(args16) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15 , const Args16 &args16 , const Args17 &args17) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) , Args16(args16) , Args17(args17) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15 , const Args16 &args16 , const Args17 &args17 , const Args18 &args18) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) , Args16(args16) , Args17(args17) , Args18(args18) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 11 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 12 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 13 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 14 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 15 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 16 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 17 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 16>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 16 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 18 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 16>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 16 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 17>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 17 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 19 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 16>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 16 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 17>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 17 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 18>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 18 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    template<typename TSeq, typename TIgnore>
    class pool<TSeq, TIgnore, typename enable_if_c<mpl::size<TSeq>::value == 20>::type>
        : public mpl::at_c<TSeq, 0>::type , public mpl::at_c<TSeq, 1>::type , public mpl::at_c<TSeq, 2>::type , public mpl::at_c<TSeq, 3>::type , public mpl::at_c<TSeq, 4>::type , public mpl::at_c<TSeq, 5>::type , public mpl::at_c<TSeq, 6>::type , public mpl::at_c<TSeq, 7>::type , public mpl::at_c<TSeq, 8>::type , public mpl::at_c<TSeq, 9>::type , public mpl::at_c<TSeq, 10>::type , public mpl::at_c<TSeq, 11>::type , public mpl::at_c<TSeq, 12>::type , public mpl::at_c<TSeq, 13>::type , public mpl::at_c<TSeq, 14>::type , public mpl::at_c<TSeq, 15>::type , public mpl::at_c<TSeq, 16>::type , public mpl::at_c<TSeq, 17>::type , public mpl::at_c<TSeq, 18>::type , public mpl::at_c<TSeq, 19>::type

    {
        template<typename T, typename = void>
        struct pool_type
        {
            typedef mpl::vector<T> type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<has_types<T> >::type>
        {
            typedef typename T::types type;
        };

        template<typename T>
        struct pool_type<T, typename enable_if<
            typename mpl::apply<TIgnore, T>::type>::type>
        {
            typedef void type;
        };

    public:
        typedef pool type;

        struct types
            : mpl::fold<
                  TSeq
                , mpl::vector0<>
                , mpl::copy<
                      pool_type<mpl::_2>
                    , mpl::back_inserter<mpl::_1>
                  >
              >::type
        { };

        pool() { }
        template< typename Args0> explicit pool( const Args0 &args0) : Args0(args0) { }

        template< typename Args0 , typename Args1> explicit pool( const Args0 &args0 , const Args1 &args1) : Args0(args0) , Args1(args1) { }

        template< typename Args0 , typename Args1 , typename Args2> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2) : Args0(args0) , Args1(args1) , Args2(args2) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15 , const Args16 &args16) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) , Args16(args16) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15 , const Args16 &args16 , const Args17 &args17) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) , Args16(args16) , Args17(args17) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15 , const Args16 &args16 , const Args17 &args17 , const Args18 &args18) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) , Args16(args16) , Args17(args17) , Args18(args18) { }

        template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19> explicit pool( const Args0 &args0 , const Args1 &args1 , const Args2 &args2 , const Args3 &args3 , const Args4 &args4 , const Args5 &args5 , const Args6 &args6 , const Args7 &args7 , const Args8 &args8 , const Args9 &args9 , const Args10 &args10 , const Args11 &args11 , const Args12 &args12 , const Args13 &args13 , const Args14 &args14 , const Args15 &args15 , const Args16 &args16 , const Args17 &args17 , const Args18 &args18 , const Args19 &args19) : Args0(args0) , Args1(args1) , Args2(args2) , Args3(args3) , Args4(args4) , Args5(args5) , Args6(args6) , Args7(args7) , Args8(args8) , Args9(args9) , Args10(args10) , Args11(args11) , Args12(args12) , Args13(args13) , Args14(args14) , Args15(args15) , Args16(args16) , Args17(args17) , Args18(args18) , Args19(args19) { }
        template<typename T, typename I>
        explicit pool(
            const pool<T, I>&
          , const init&
          , typename enable_if_c<
                mpl::size<typename pool<T, I>::types>::value == 0
            >::type* = 0)
        { }
        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 1 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 2 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 3 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 4 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 5 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 6 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 7 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 8 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 9 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 10 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 11 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 12 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 13 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 14 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 15 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 16 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 17 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 16>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 16 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 18 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 16>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 16 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 17>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 17 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 19 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 16>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 16 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 17>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 17 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 18>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 18 >::type >() ) { }

        template<typename T, typename I> explicit pool( const pool<T, I>& p , const init& , typename enable_if_c< mpl::size<typename pool<T, I>::types>::value == 20 >::type* = 0) : mpl::at_c<typename pool<T, I>::types, 0>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 0 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 1>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 1 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 2>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 2 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 3>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 3 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 4>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 4 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 5>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 5 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 6>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 6 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 7>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 7 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 8>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 8 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 9>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 9 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 10>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 10 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 11>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 11 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 12>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 12 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 13>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 13 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 14>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 14 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 15>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 15 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 16>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 16 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 17>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 17 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 18>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 18 >::type >() ) , mpl::at_c<typename pool<T, I>::types, 19>::type( p.template get< typename mpl::at_c< typename pool<T, I>::types , 19 >::type >() ) { }

        template<typename T>
        const T& get() const {
            return static_cast<const T&>(*this);
        }
    };

    }
    }
    }


    namespace boost {
    namespace di {
    namespace detail {

    template<typename TBinder>
    class creator
    {
        template<typename TDependency>
        struct ctor
            : type_traits::ctor_traits<typename TDependency::given>::type
        { };

        template<typename T, typename TCallStack>
        struct binder
            : TBinder::template resolve<T, TCallStack>::type
        { };

        template<
            typename T
          , typename TCallStack
          , typename TDependency
        >
        struct dependency
        {
            typedef T type;
            typedef TCallStack call_stack;
            typedef typename TDependency::given given;
            typedef typename TDependency::expected expected;
            typedef typename TDependency::scope scope;
        };

        BOOST_MPL_HAS_XXX_TRAIT_DEF(named_type)

        template<
            typename T
          , typename TCallStack
          , typename TPolicies
          , typename TDeps
          , typename TScopes
          , typename TRefs
          , typename TVisitor
        >
        class eager_creator
        {
            typedef typename type_traits::make_plain<T>::type plain_t;

            template<typename U, typename = void>
            struct named_type
            {
                typedef U type;
            };

            template<typename U>
            struct named_type<U, typename enable_if<
                has_named_type<typename type_traits::remove_accessors<U>::type> >::type
            >
            {
                typedef typename type_traits::remove_accessors<typename U::named_type>::type type;
            };

        public:
            eager_creator(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor)
                : deps_(deps), scopes_(scopes), refs_(refs), visitor_(visitor)
            { }

            template<
                typename U

              , typename NU = typename named_type<U>::type
              , typename PU = typename type_traits::make_plain<U>::type
              , typename = typename disable_if<type_traits::is_same_base_of<PU, plain_t> >::type

            >
            operator U() {

                return creator::execute_impl<
                    NU
                  , typename mpl::push_back<TCallStack, PU>::type
                  , TPolicies
                  , binder<U, TCallStack>
                >(deps_, scopes_, refs_, visitor_)(boost::type<NU>());
            }

            template<
                typename U

              , typename NU = typename named_type<U>::type
              , typename PU = typename type_traits::make_plain<U>::type
              , typename = typename disable_if<type_traits::is_same_base_of<PU, plain_t> >::type

            >
            operator const U&() const {

                return creator::execute_impl<
                    const U&
                  , typename mpl::push_back<TCallStack, PU>::type
                  , TPolicies
                  , binder<const U&, TCallStack>
                >(deps_, scopes_, refs_, visitor_)(boost::type<const NU&>());
            }

            template<
                typename U

              , typename NU = typename named_type<U>::type
              , typename PU = typename type_traits::make_plain<U>::type
              , typename = typename disable_if<type_traits::is_same_base_of<PU, plain_t> >::type

            >
            operator U&() const {

                return creator::execute_impl<
                    U&
                  , typename mpl::push_back<TCallStack, PU>::type
                  , TPolicies
                  , binder<U&, TCallStack>
                >(deps_, scopes_, refs_, visitor_)(boost::type<NU&>());
            }

        private:
            TDeps& deps_;
            TScopes& scopes_;
            TRefs& refs_;
            const TVisitor& visitor_;
        };

    public:
        template<
            typename T
          , typename TParent
          , typename TCallStack
          , typename TPolicies
          , typename TDeps
          , typename TScopes
          , typename TRefs
          , typename TVisitor
        >
        static eager_creator<TParent, TCallStack, TPolicies, TDeps, TScopes, TRefs, TVisitor>
        execute(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor
              , typename enable_if<is_same<T, any_type> >::type* = 0) {
            return eager_creator<TParent, TCallStack, TPolicies, TDeps, TScopes, TRefs, TVisitor>(
                deps, scopes, refs, visitor
            );
        }

        template<
            typename T
          , typename
          , typename TCallStack
          , typename TPolicies
          , typename TDeps
          , typename TScopes
          , typename TRefs
          , typename TVisitor
        >
        static const typename binder<T, TCallStack>::result_type&
        execute(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor
              , typename disable_if<is_same<T, any_type> >::type* = 0) {
            return execute_impl<
                T
              , typename mpl::push_back<
                    TCallStack
                  , typename binder<T, TCallStack>::given
                >::type
              , TPolicies
              , binder<T, TCallStack>
            >(deps, scopes, refs, visitor);
        }

    private:

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 0
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                   

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 1
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 2
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 3
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 4
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 5
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 6
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 7
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 8
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 9
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 10
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 11
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 10 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 12
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 10 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 11 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 13
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 10 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 11 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 12 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 14
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 10 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 11 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 12 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 13 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 15
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 10 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 11 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 12 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 13 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 14 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 16
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 10 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 11 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 12 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 13 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 14 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 15 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 17
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 10 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 11 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 12 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 13 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 14 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 15 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 16 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 18
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 10 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 11 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 12 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 13 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 14 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 15 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 16 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 17 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 19
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 10 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 11 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 12 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 13 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 14 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 15 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 16 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 17 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 18 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

    template<
        typename T
      , typename TCallStack
      , typename TPolicies
      , typename TDependency
      , typename TDeps
      , typename TScopes
      , typename TRefs
      , typename TVisitor
    >
    static typename enable_if_c<
        mpl::size<typename ctor<TDependency>::type>::value == 20
      , const typename TDependency::result_type&
    >::type execute_impl(TDeps& deps, TScopes& scopes, TRefs& refs, const TVisitor& visitor) {
        typedef dependency<T, TCallStack, TDependency> dependency_type;
        assert_policies<TPolicies, typename TDeps::types, dependency_type>();
        (visitor)(dependency_type());

        typedef typename TDependency::result_type convertible_type;
        convertible_type* convertible =
            new convertible_type(
                acquire<typename TDependency::type>(deps, scopes).create(
                    execute< typename mpl::at_c< typename ctor<TDependency>::type , 0 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 1 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 2 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 3 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 4 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 5 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 6 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 7 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 8 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 9 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 10 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 11 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 12 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 13 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 14 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 15 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 16 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 17 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 18 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor) , execute< typename mpl::at_c< typename ctor<TDependency>::type , 19 >::type , T , TCallStack , TPolicies >(deps, scopes, refs, visitor)

                )
            );

        refs.push_back(aux::shared_ptr<void>(convertible));

        return *convertible;
    }

        template<
            typename TDependency
          , typename TDeps
          , typename TScopes
        >
        static typename enable_if<is_base_of<TDependency, TDeps>, TDependency&>::type
        acquire(TDeps& deps, TScopes&) {
            return static_cast<TDependency&>(deps);
        }

        template<
            typename TDependency
          , typename TDeps
          , typename TScopes
        >
        static typename disable_if<is_base_of<TDependency, TDeps>, TDependency&>::type
        acquire(TDeps&, TScopes& scopes) {
            typename TScopes::const_iterator it = scopes.find(&typeid(TDependency));
            if (it != scopes.end()) {
                return *static_cast<TDependency*>(it->second.get());
            }

            TDependency* dependency = new TDependency();
            scopes[&typeid(TDependency)] = aux::shared_ptr<void>(dependency);
            return *dependency;
        }

        template<typename TSeq, typename TDeps, typename T>
        static typename enable_if<mpl::empty<TSeq> >::type assert_policies() { }

        template<typename TSeq, typename TDeps, typename T>
        static typename disable_if<mpl::empty<TSeq> >::type assert_policies() {
            typedef typename mpl::front<TSeq>::type policy;
            policy::template assert_policy<TDeps, T>();
            assert_policies<typename mpl::pop_front<TSeq>::type, TDeps, T>();
        }
    };

    }
    }
    }


    namespace boost {
    namespace di {
    namespace detail {

    template<
        typename TDeps = mpl::vector0<>
      , template<typename> class TBinder = binder
      , template<
            typename
          , typename = ::boost::di::detail::never< ::boost::mpl::_1 >
          , typename = void
        > class TPool = pool
      , template<typename> class TCreator = creator
    >
    class module : public TPool<TDeps>
    {
        BOOST_MPL_HAS_XXX_TRAIT_DEF(scope)

        template<
            typename
          , template<typename> class
          , template<typename, typename, typename> class
          , template<typename> class
        > friend class module;

        template<typename T>
        class has_call_impl
        {
            struct base_impl { void call() { } };
            struct base : T, base_impl { base() { } };

            template<typename U>
            static mpl::aux::no_tag test(
                U*
              , non_type<void (base_impl::*)(), &U::call>* = 0
            );

            template<typename>
            static mpl::aux::yes_tag test(...);

        public:
            typedef has_call_impl type;

            BOOST_STATIC_CONSTANT(
                bool
              , value = sizeof(test<base>(0)) == sizeof(mpl::aux::yes_tag)
            );
        };

        template<typename T, typename TAction>
        class has_call
        {
            template<typename>
            struct void_ { };

            template<typename S, typename U>
            friend U& operator,(const U&, void_<S>);

            struct base : T
            {
                base() { }
                using T::call;
                mpl::aux::no_tag call(...) const;
            };

            template<typename, typename = void>
            struct base_call
                : mpl::false_
            { };

            template<typename TDummy>
            struct base_call<mpl::true_, TDummy>
                : is_same<
                      BOOST_TYPEOF_TPL(
                         ((((base*)0)->call(*(TAction*)0)), void_<T>())
                      )
                    , void_<T>
                  >
            { };

        public :
            typedef has_call type;

            BOOST_STATIC_CONSTANT(
                bool
              , value = base_call<mpl::bool_<has_call_impl<T>::value> >::value
            );
        };

        template<typename T>
        class has_assert_policy
        {
            struct base_impl { static void assert_policy() { }; };

            struct base
                : base_impl
                , mpl::if_<is_class<T>, T, mpl::void_>::type
            { base() { } };

            template<typename U>
            static mpl::aux::no_tag test(
                U*
              , non_type<void(*)(), &U::assert_policy>* = 0
            );

            static mpl::aux::yes_tag test(...);

        public:
            typedef has_assert_policy type;

            BOOST_STATIC_CONSTANT(
                bool
              , value = !has_scope<T>::value &&
                        sizeof(test((base*)(0))) == sizeof(mpl::aux::yes_tag)
            );
        };

        template<
            typename T
          , typename TCallStack
          , typename TBind
        >
        struct binder
            : TBind::template resolve<T, TCallStack>::type
        { };

        class empty_visitor
        {
        public:
            template<typename T>
            void operator()(const T&) const { }
        };

        class type_comparator
        {
        public:
            bool operator ()(const std::type_info* lhs, const std::type_info* rhs) const {
                return lhs->before(*rhs);
            }
        };

    public:
        typedef TDeps deps;

        module() { }

    template< typename Args0>
    explicit module( Args0 args0)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0)
            , init()
          )
    { }

    template<typename T, typename Args0>
    T create( Args0 ) {
        typedef mpl::vector< Args0> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1>
    explicit module( Args0 args0 , Args1 args1)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1>
    T create( Args0 , Args1 ) {
        typedef mpl::vector< Args0 , Args1> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2>
    T create( Args0 , Args1 , Args2 ) {
        typedef mpl::vector< Args0 , Args1 , Args2> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3>
    T create( Args0 , Args1 , Args2 , Args3 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    explicit module( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18 , Args19 args19)
        : TPool<deps>(
              TPool<
                  mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19>
                , mpl::not_<
                      mpl::or_<
                          mpl::contains<deps, mpl::_>
                        , has_types<mpl::_>
                      >
                  >
              >( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18 , args19)
            , init()
          )
    { }

    template<typename T, typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    T create( Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19 ) {
        typedef mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19> policies;
        std::vector<aux::shared_ptr<void> > refs_;

        return TCreator<TBinder<deps> >::template
            execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
    }

        template<typename T>
        T create() {
            typedef mpl::vector0<> policies;
            std::vector<aux::shared_ptr<void> > refs_;

            return TCreator<TBinder<deps> >::template
                execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, empty_visitor())(boost::type<T>());
        }

        template<typename T, typename Visitor>
        T visit(const Visitor& visitor) {
            typedef mpl::vector0<> policies;
            std::vector<aux::shared_ptr<void> > refs_;

            return TCreator<TBinder<deps> >::template
                execute<T, T, mpl::vector0<>, policies>(static_cast<TPool<deps>&>(*this), scopes_, refs_, visitor)(boost::type<T>());
        }

        template<typename TAction>
        void call(const TAction& action) {
            call_impl<deps>(static_cast<TPool<deps>&>(*this), action);
        }

    private:
        template<typename TSeq, typename T, typename TAction>
        typename enable_if<mpl::empty<TSeq> >::type call_impl(T&, const TAction&) { }

        template<typename TSeq, typename T, typename TAction>
        typename disable_if<mpl::empty<TSeq> >::type call_impl(
            T& deps
          , const TAction& action
          , typename enable_if<has_call<typename mpl::front<TSeq>::type, TAction> >::type* = 0) {
            static_cast<typename mpl::front<TSeq>::type&>(deps).call(action);
            call_impl<typename mpl::pop_front<TSeq>::type>(deps, action);
        }

        template<typename TSeq, typename T, typename TAction>
        typename disable_if<mpl::empty<TSeq> >::type call_impl(
            T& deps
          , const TAction& action
          , typename disable_if<has_call<typename mpl::front<TSeq>::type, TAction> >::type* = 0) {
            call_impl<typename mpl::pop_front<TSeq>::type>(deps, action);
        }

        std::map<const std::type_info*, aux::shared_ptr<void>, type_comparator> scopes_;
    };

    }
    }
    }


namespace boost {
namespace di {

template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
struct call_stack
    : mpl::vector< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19>
{ };

template<typename TScope>
struct scope
    : concepts::scope<TScope, concepts::dependency>
{ };

template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
struct deduce
    : scope<scopes::deduce>::bind< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19>
{ };

template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
struct unique
    : scope<scopes::unique<> >::bind< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19>
{ };

template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
struct shared
    : scope<scopes::shared<> >::bind< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19>
{ };

template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
struct session
    : scope<scopes::session<> >::bind< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19>
{ };

template<typename TExpected, typename TGiven = TExpected>
struct bind
    : concepts::bind<TExpected, TGiven, concepts::dependency>
{ };

template<int N>
struct bind_int
    : bind<int, mpl::int_<N> >
{ };

template<typename T>
struct bind_string
    : bind<std::string, T>
{ };

}
}

namespace boost {
namespace di {

template<typename T>
class provider
{
public:
    virtual ~provider() { }
    virtual T get() const = 0;
};

}
}


    namespace boost {
    namespace di {

    namespace detail {

    template<typename T>
    struct default_scope
        : scope<scopes::deduce>::bind<T>
    { };

    BOOST_MPL_HAS_XXX_TRAIT_DEF(deps)

    template<typename T>
    struct deps
    {
        typedef typename T::deps type;
    };

    template<typename TSeq>
    struct concepts
        : mpl::fold<
              TSeq
            , mpl::vector0<>
            , mpl::copy<
                  mpl::if_<
                      mpl::is_sequence<mpl::_2>
                    , mpl::_2
                    , mpl::if_<
                          has_deps<mpl::_2>
                        , deps<mpl::_2>
                        , default_scope<mpl::_2>
                      >
                  >
                , mpl::back_inserter<mpl::_1>
              >
          >::type
    { };

    }

    template< typename T0 = ::boost::mpl::na , typename T1 = ::boost::mpl::na , typename T2 = ::boost::mpl::na , typename T3 = ::boost::mpl::na , typename T4 = ::boost::mpl::na , typename T5 = ::boost::mpl::na , typename T6 = ::boost::mpl::na , typename T7 = ::boost::mpl::na , typename T8 = ::boost::mpl::na , typename T9 = ::boost::mpl::na , typename T10 = ::boost::mpl::na , typename T11 = ::boost::mpl::na , typename T12 = ::boost::mpl::na , typename T13 = ::boost::mpl::na , typename T14 = ::boost::mpl::na , typename T15 = ::boost::mpl::na , typename T16 = ::boost::mpl::na , typename T17 = ::boost::mpl::na , typename T18 = ::boost::mpl::na , typename T19 = ::boost::mpl::na >
    class injector
        : public detail::module<
              typename detail::concepts<
                  mpl::vector< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19>
              >::type
          >
    {
        template<typename TSeq = mpl::vector0<> >
        struct joint_concepts
            : detail::concepts<
                  mpl::joint_view<
                      mpl::vector< T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19>
                    , TSeq
                  >
              >::type
        { };

    public:
        injector() { }

        injector<> operator()() const {
            return injector<>();
        }

    template< typename Args0>
    explicit injector( Args0 args0)
        : detail::module<typename joint_concepts<>::type>( args0)
    { }

    template< typename Args0>
    injector<joint_concepts<mpl::vector< Args0> > >
    operator()( Args0 args0) const {
        return injector<joint_concepts<mpl::vector< Args0> > >(
            args0
        );
    }

    template< typename Args0 , typename Args1>
    explicit injector( Args0 args0 , Args1 args1)
        : detail::module<typename joint_concepts<>::type>( args0 , args1)
    { }

    template< typename Args0 , typename Args1>
    injector<joint_concepts<mpl::vector< Args0 , Args1> > >
    operator()( Args0 args0 , Args1 args1) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1> > >(
            args0 , args1
        );
    }

    template< typename Args0 , typename Args1 , typename Args2>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2)
    { }

    template< typename Args0 , typename Args1 , typename Args2>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2> > >(
            args0 , args1 , args2
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3> > >(
            args0 , args1 , args2 , args3
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4> > >(
            args0 , args1 , args2 , args3 , args4
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5> > >(
            args0 , args1 , args2 , args3 , args4 , args5
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    explicit injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18 , Args19 args19)
        : detail::module<typename joint_concepts<>::type>( args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18 , args19)
    { }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19> > >
    operator()( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18 , Args19 args19) const {
        return injector<joint_concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19> > >(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18 , args19
        );
    }
    };

    }
    }


    namespace boost {
    namespace di {

    inline injector<> make_injector() {
        return injector<>()();
    }

    template< typename Args0>
    injector<typename detail::concepts<mpl::vector< Args0> >::type>
    inline make_injector( Args0 args0) {
        return injector<typename detail::concepts<mpl::vector< Args0> >::type>(
            args0
        );
    }

    template< typename Args0 , typename Args1>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1> >::type>
    inline make_injector( Args0 args0 , Args1 args1) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1> >::type>(
            args0 , args1
        );
    }

    template< typename Args0 , typename Args1 , typename Args2>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2> >::type>(
            args0 , args1 , args2
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3> >::type>(
            args0 , args1 , args2 , args3
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4> >::type>(
            args0 , args1 , args2 , args3 , args4
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18
        );
    }

    template< typename Args0 , typename Args1 , typename Args2 , typename Args3 , typename Args4 , typename Args5 , typename Args6 , typename Args7 , typename Args8 , typename Args9 , typename Args10 , typename Args11 , typename Args12 , typename Args13 , typename Args14 , typename Args15 , typename Args16 , typename Args17 , typename Args18 , typename Args19>
    injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19> >::type>
    inline make_injector( Args0 args0 , Args1 args1 , Args2 args2 , Args3 args3 , Args4 args4 , Args5 args5 , Args6 args6 , Args7 args7 , Args8 args8 , Args9 args9 , Args10 args10 , Args11 args11 , Args12 args12 , Args13 args13 , Args14 args14 , Args15 args15 , Args16 args16 , Args17 args17 , Args18 args18 , Args19 args19) {
        return injector<typename detail::concepts<mpl::vector< Args0 , Args1 , Args2 , Args3 , Args4 , Args5 , Args6 , Args7 , Args8 , Args9 , Args10 , Args11 , Args12 , Args13 , Args14 , Args15 , Args16 , Args17 , Args18 , Args19> >::type>(
            args0 , args1 , args2 , args3 , args4 , args5 , args6 , args7 , args8 , args9 , args10 , args11 , args12 , args13 , args14 , args15 , args16 , args17 , args18 , args19
        );
    }

    }
    }

#endif
