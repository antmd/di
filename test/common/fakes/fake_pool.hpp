//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef BOOST_DI_FAKE_POOL_HPP
#define BOOST_DI_FAKE_POOL_HPP

namespace boost { namespace di {

template<class... T>
struct fake_pool : T...  { };

} // boost::di

#endif

