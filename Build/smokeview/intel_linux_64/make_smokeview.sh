#!/bin/bash
source ../../scripts/setopts.sh $*

# Exit immediately if any of the build steps fail
set -e

LIBDIR=../../LIBS/intel_linux_64/
eval make -C ${LIBDIR} ${SMV_MAKE_OPTS} -f make_LIBS.make all

export IFORT_COMPILER_LIB=/sw/easybuild/software/iccifort/2019.5.281/compilers_and_libraries_2019.5.281/linux/compiler/lib/intel64_lin
make -f ../Makefile clean
eval make -j 4 ${SMV_MAKE_OPTS} -f ../Makefile intel_linux_64
