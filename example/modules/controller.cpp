//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

//[controller_cpp
//<-
#include <cassert>
#include "controller.hpp"
//->

int controller::run() {
    assert(view_.get());
    assert(model_.get());

    return 0;
}

//]

