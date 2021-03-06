#!/bin/bash
#
# Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#

bind_interfaces() {
    for ((i=1; i<=$1; ++i)); do
        echo -n "-DMODULE$i -DBIND_INTERFACES$i(...)=__VA_ARGS__ -DBIND_OTHERS$i(...)= "
    done
}

bind_others() {
    for ((i=1; i<=$1; ++i)); do
        echo -n "-DMODULE$i -DBIND_INTERFACES$i(...)= -DNO_CTOR_INTERFACES$i -DBIND_OTHERS$i(...)=__VA_ARGS__ "
    done
}

bind_interfaces_others() {
    for ((i=1; i<=$1; ++i)); do
        if [ "$2" -ge "$1" ]; then
            echo -n "-DMODULE$i -DBIND_INTERFACES$i(...)=__VA_ARGS__, -DBIND_OTHERS$i(...)=__VA_ARGS__ "
        else
            echo -n "-DMODULE$i -DBIND_INTERFACES$i(...)=__VA_ARGS__ -DBIND_OTHERS$i(...)= "
        fi
    done
}

bind_all() {
    for ((i=1; i<=$1; ++i)); do
        echo -n "-DMODULE$i -DBIND_INTERFACES$i(...)=__VA_ARGS__, -DBIND_OTHERS$i(...)=__VA_ARGS__ "
    done
}

benchmark() {
    CTOR=`[ "$2" == "ctor" ] && echo -n "-DBOOST_DI_INJECT(type, ...)=type(__VA_ARGS__)"`
    EXPOSED_OR_AUTO=`[ "$3" == "auto" ] && echo -n "-DEXPOSED_OR_AUTO(t1, t2)=t2" || echo -n "-DEXPOSED_OR_AUTO(t1, t2)=t1"`
    (time clang++ -O2 di.cpp -std=c++1y -I ../../include "$CTOR" "$EXPOSED_OR_AUTO" `$4` -DCOMPLEX=$1) 2> /tmp/$0.dat
    if [[ "`grep error: /tmp/$0.dat`" != "" ]]; then
        >&2 cat /tmp/$0.dat
        exit
    fi
    cat /tmp/$0.dat | grep real | awk '{print $2}' | sed "s/0m\(.*\)s/\1/" | tr '\n' ' '
}

graph() {
    rm -f $1.pg $1.dat
    `echo $1` > $1.dat
    echo -e "set terminal png
             set xlabel \"Number of bindings\"
             set ylabel \"Time [s]\"
             set title \"$2\"
             set key reverse Left outside
             set grid
             set style data linespoints
             plot \"$1.dat\" \
                  using 1:2 title \"ctor/all\" \
           , \"\" using 1:3 title \"inject/all\" \
           , \"\" using 1:4 title \"ctor/exposed\" \
           , \"\" using 1:5 title \"inject/exposed\"
    " > $1.pg
    gnuplot $1.pg > $1.png
}

small_complexity() {
    for ((i=0; i<=10; ++i)); do
        echo -n "$((i*20)) "
        benchmark small_complexity ctor auto "bind_others $i"
        benchmark small_complexity inject auto "bind_others $i"
        benchmark small_complexity ctor exposed "bind_others $i"
        benchmark small_complexity inject exposed "bind_others $i"
        echo
    done
}

medium_complexity() {
    for ((i=0; i<=10; ++i)); do
        echo -n "$((i*20)) "
        benchmark medium_complexity ctor auto "bind_others $i"
        benchmark medium_complexity inject auto "bind_others $i"
        benchmark medium_complexity ctor exposed "bind_others $i"
        benchmark medium_complexity inject exposed "bind_others $i"
        echo
    done
}

big_complexity() {
    for ((i=0; i<=10; ++i)); do
        echo -n "$((100+(i*20))) "
        benchmark big_complexity ctor auto "bind_interfaces_others 10 $i"
        benchmark big_complexity ctor exposed "bind_interfaces_others 10 $i"
        benchmark big_complexity inject auto "bind_interfaces_others 10 $i"
        benchmark big_complexity inject exposed "bind_interfaces_others 10 $i"
        echo
    done
}

graph small_complexity "Small complexity | clang-3.4 -O2"
graph medium_complexity "Medium complexity | clang-3.4 -O2"
graph big_complexity "Big complexity | clang-3.4 -O2"

