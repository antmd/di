//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include <cassert>
#include <boost/mpl/string.hpp>
#include <boost/di.hpp>

namespace mpl = boost::mpl;
namespace di  = boost::di;

namespace {

class named
{
public:
    BOOST_DI_INJECT(named
      , di::named<int, mpl::string<'1'>> i1
      , di::named<int, mpl::string<'2'>> i2
    ) : i1(i1), i2(i2) {
        assert(i1 == 42);
        assert(i2 == 87);
    }

private:
    int i1 = 0;
    int i2 = 0;
};

} // namespace

int main() {
    di::injector<
        di::bind_int<42>::in_name<mpl::string<'1'>>
      , di::bind_int<87>::in_name<mpl::string<'2'>>
    >().create<named>();

    return 0;
}
