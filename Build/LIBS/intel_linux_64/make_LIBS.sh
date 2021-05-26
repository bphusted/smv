#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR

# use -I to force use of the gnu compiler
OPTS="-I $*"
source ../../../Source/scripts/setopts.sh $OPTS

if [[ "$target" == "all" ]] || [[ "$target" == "clean" ]]; then
  rm *.a
  if [ "$target" == "clean" ]; then
    exit
  fi
fi

LIBDIR=`pwd`

SRCDIR=$LIBDIR/../../../Source
cd $SRCDIR
SRCDIR=`pwd`

cd ../Build
BUILDDIR=`pwd`

# GLUT

if [[ "$target" == "all" ]] || [[ "$target" == "glut" ]]; then
if [ "$GLUT" == "freeglut" ]; then
  echo "********** building freeglut"
  cd $BUILDDIR/freeglut3.0.0/gnu_linux_64 >& freeglut.out
  ./make_freeglut.sh $OPTS >& $LIBDIR/freeglut.out
else
  echo "********** building glut"
  cd $SRCDIR/glut-3.7.6
  ./makelib.sh $OPTS >& $LIBDIR/glut.out
fi
cp libglut.a $LIBDIR/.
fi

if [[ "$target" == "all" ]] || [[ "$target" == "glui" ]]; then
# GLUI
echo "********** building glui"
cd $SRCDIR/glui_v2_1_beta
./makelib.sh $OPTS >& $LIBDIR/glui.out
cp libglui.a $LIBDIR/.
fi

if [[ "$target" == "all" ]] || [[ "$target" == "zlib" ]]; then
# ZLIB
echo "********** building zlib"
cd $SRCDIR/zlib128
./makelib.sh $OPTS >& $LIBDIR/zlib.out
cp libz.a $LIBDIR/.
fi

if [[ "$target" == "all" ]] || [[ "$target" == "jpeg" ]]; then
# JPEG
echo "********** building jpeg"
cd $SRCDIR/jpeg-9b
./makelib.sh $OPTS >& $LIBDIR/jpeg.out
cp libjpeg.a $LIBDIR/.
fi

if [[ "$target" == "all" ]] || [[ "$target" == "png" ]]; then
# PNG
echo "********** building png"
cd $SRCDIR/png-1.6.21
./makelib.sh $OPTS >& $LIBDIR/png.out
cp libpng.a $LIBDIR/.
fi

if [[ "$target" == "all" ]] || [[ "$target" == "gd" ]]; then
# GD
echo "********** building gd"
cd $SRCDIR/gd-2.0.15
./makelib.sh $OPTS >& $LIBDIR/gd.out
cp libgd.a $LIBDIR/.
fi

if [[ "$target" == "all" ]] || [[ "$arg" == "lua" ]]; then
# LUA variable is set by passing -l to this script (lower case L)
if [ "$LUA" == "lua" ]; then

# Lua # Lua interpreter
cd $SRCDIR/lua-5.3.1/src
export TARGET=liblua.a
echo "********** building lua"
./makelib.sh $OPTS >& $LIBDIR/lua.out
cp liblua.a $LIBDIR/.

# LPEG # Lua parsing libarary to parse SSF files
cd $SRCDIR/lpeg-1.0.0
export TARGET=linux
echo "********** building lpeg"
./makelib.sh $OPTS >& $LIBDIRE/lpeg.out
cp lpeg.so $LIBDIR/.
fi
fi
