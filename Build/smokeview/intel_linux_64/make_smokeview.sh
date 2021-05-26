#!/bin/bash
source ../../scripts/setopts.sh $*

# Exit immediately if any of the build steps fail
set -e

curdir=`pwd`
LIBDIR=../../LIBS/intel_linux_64/
if [ "$BUILD_LIBS" == "1" ]; then
  cd $LIBDIR
  ./make_LIBS.sh
  cd $curdir
else
  eval make -C ${LIBDIR} ${SMV_MAKE_OPTS} -f make_LIBS.make all
fi
export IFORT_COMPILER_LIB=/sw/easybuild/software/iccifort/2019.5.281/compilers_and_libraries_2019.5.281/linux/compiler/lib/intel64_lin
if [ "$BUILD_ALL" == "1" ]; then
  make -f ../Makefile clean
fi
eval make -j 4 ${SMV_MAKE_OPTS} -f ../Makefile intel_linux_64
