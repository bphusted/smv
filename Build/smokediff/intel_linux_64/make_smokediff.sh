#!/bin/bash
module purge
module load compiler/iccifort/2020.4.304
export IFORT_COMPILER_LIB=/sw/easybuild/software/iccifort/2020.4.304/compilers_and_libraries/linux/lib/intel64_lin
rm -f *.o smokediff_linux_64
make -f ../Makefile intel_linux_64
