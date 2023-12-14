#!/bin/bash

# add -A to any case that you wish to be a part of the benchmark timing suite

$QFDS -d WUI -t -A wind_test2_bench.fds

#$QFDS -p 16 -n 8 -d WUI BT10m_2x2km_LS.fds
$QFDS -p 2  -d WUI hill_structure.fds
$QFDS -p 18  -n 6 -d WUI levelset2.fds
$QFDS -p 4  -d WUI pine_tree.fds
$QFDS       -d WUI tree_test2.fds
$QFDS       -d WUI wind_test1.fds
$QFDS -p 2  -d WUI wind_test2.fds
