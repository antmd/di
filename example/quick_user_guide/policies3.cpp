//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#define BOOST_DI_CFG all_must_be_bound_unless_int
#include <boost/di.hpp>
#include <boost/di/policies/constructible.hpp>
#include <type_traits>
#include <cassert>

namespace di = boost::di;

class all_must_be_bound_unless_int : public di::config {
public:
    auto policies() const noexcept {
        using namespace di::policies;
        using namespace di::policies::operators;

        return di::make_policies(
            constructible(std::is_same<_, int>{} || is_bound<_>{})
        );
    }
};

int main() {
    assert(0 == di::make_injector().create<int>());
    //di::make_injector().create<double>(); // compile error
    assert(42.0 == make_injector(
                     di::bind<double>.to(42.0)
                 ).create<double>()
    );
}

