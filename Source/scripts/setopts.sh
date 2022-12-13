#!/bin/bash
if [ "`uname`" == "Darwin" ]; then
# The Mac doesn't have new compilers
  if [ "$INTEL_ICC" == "" ]; then
    INTEL_ICC="icc"
  fi
  if [ "$INTEL_ICPP" == "" ]; then
    INTEL_ICPP="icpc"
  fi
else
  if [ "$INTEL_ICC" == "" ]; then
    INTEL_ICC="icx"
  fi
  if [ "$INTEL_ICPP" == "" ]; then
    INTEL_ICPP="icpx"
  fi
fi
COMPILER=$INTEL_ICC
COMPILER2=$INTEL_ICPP

PLATFORM=""
GLUT=glut
LUA=
FOREC_g=
FOREC_i=
target=all
QUARTZ="framework"
while getopts 'fgGhiILlqQt:T' OPTION
do
case $OPTION in
  f)
   GLUT="freeglut"
  ;;
  g)
   if [ "$FORCE_i" == "" ]; then
     COMPILER="gcc"
     COMPILER2="g++"
   fi
  ;;
  G)
   COMPILER="gcc"
   COMPILER2="g++"
   FORCE_g=1
  ;;
  h)
  echo "options:"
  echo "-f - use freeglut (not glut)
  echo "-g - use the gnu gcc compiler"
  echo "-i - use the Intel icc compiler"
  echo "-l - use lua 
  echo "-q - on the Mac use the X11 include files and libraries supplied by Quartz"
  echo "-t target - makefile target"
  exit
  ;;
  i)
   if [ "$FORCE_g" == "" ]; then
     if [ "`uname`" == "Darwin" ]; then
       COMPILER="icc"
       COMPILER2="icpc"
     else 
       COMPILER=$INTEL_ICC
       COMPILER2=$INTEL_ICPP
     fi       
   fi
  ;;
  I)
    if [ "`uname`" == "Darwin" ]; then
     COMPILER="icc"
     COMPILER2="icpc"
   else 
     COMPILER=$INTEL_ICC
     COMPILER2=$INTEL_ICPP
   fi       
   FORCE_i=1
  ;;
  l)
   LUA=lua
  ;;
  L)
   dummy=1
  ;;
  q)
   QUARTZ="-I /opt/X11/include -Wno-unknown-pragmas"
  ;;
  Q)
   QUARTZ=framework
  ;;
  t)
   target="$OPTARG"
  ;;
  T)
   dummy=1
  ;;
esac
done
shift $(($OPTIND-1))

# the parameter QUARTZ is only for the mac
if [ "`uname`" == "Darwin" ]; then
  if [ "$QUARTZ" == "framework" ]; then
    PLATFORM="-D pp_OSX -D pp_NOQUARTZ"
    if [ "$LOWRES" != "" ]; then
      PLATFORM="$PLATFORM -D pp_OSX_LOWRES"
    fi
  else
    PLATFORM="-D pp_OSX -D pp_QUARTZ $QUARTZ"
  fi
  export QUARTZ
else
  PLATFORM="-D pp_LINUX"
  QUARTZ=
fi
export COMPILER
export PLATFORM
export GLUT
export LUA
export target
