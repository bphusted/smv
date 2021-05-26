#!/bin/bash
rm -f *.o
source ../scripts/setopts.sh $*

rm -f *.o
eval make -j 4 COMPILER=${COMPILER} SIZE=${SIZE} PLATFORM=\"${PLATFORM}\" ${TARGET}
