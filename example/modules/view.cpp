//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

//[view_cpp
//<-
#include <cassert>
#include "view.hpp"
//->

view::view(std::unique_ptr<iwindow> w, std::shared_ptr<ibutton> b) {
    assert(w.get());
    assert(b.get());
}

//]

