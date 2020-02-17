#!/bin/bash
source ../../scripts/setopts.sh $*

LIBDIR=../../LIBS/intel_osx_64/
eval make -C ${LIBDIR} ${SMV_MAKE_OPTS} ${LUA_SCRIPTING} -f make_LIBS.make all_nolua_noglut

make -f ../Makefile clean
eval make -j 4 ${SMV_MAKE_OPTS} -f ../Makefile intel_osx_64_db
