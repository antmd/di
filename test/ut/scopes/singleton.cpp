//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include <string>
#include "boost/di/scopes/singleton.hpp"
#include "common/fakes/fake_provider.hpp"

namespace boost { namespace di { namespace scopes {

test create_singleton = [] {
    singleton::scope<int, int> singleton;

    std::shared_ptr<int> object1 = singleton.create<int>(fake_provider<int>{});
    std::shared_ptr<int> object2 = singleton.create<int>(fake_provider<int>{});

    expect_eq(object1, object2);
};

}}} // boost::di::scopes

