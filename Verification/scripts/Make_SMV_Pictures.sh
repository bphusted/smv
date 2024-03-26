#!/bin/bash

# --------------------- wait_cases_end -----------------------------

wait_cases_end()
{
  if [ "$QUEUE" == "none" ]; then
    while [[ `ps -u $USER -f | fgrep .fds | grep -v grep` != '' ]]; do
        JOBS_REMAINING=`ps -u $USER -f | fgrep .fds | grep -v grep | wc -l`
        echo "Waiting for ${JOBS_REMAINING} cases to complete."
        sleep 15
     done
  else
    while [[ `qstat -a | awk '{print $2 $4 $10}' | grep $(whoami) | grep $JOBPREFIX | grep -v 'C$'` != '' ]]; do
       JOBS_REMAINING=`qstat -a | awk '{print $2 $4 $10}' | grep $(whoami) | grep $JOBPREFIX | grep -v 'C$' | wc -l`
       echo "Waiting for ${JOBS_REMAINING} cases to complete."
       sleep 15
    done
  fi
}

# --------------------- usage -----------------------------

function usage {
echo "Make_SMV_Pictures.sh [-d -h -r]"
echo "Generates figures for Smokeview verification suite"
echo ""
echo "Options"
echo "-C - use gnu compiled version of smokeview"
echo "-d - use debug version of smokeview"
echo "-h - display this message"
echo "-i - use installed version of smokeview"
echo "-q q - queue used to generate images"
echo "-t - use test version of smokeview"
echo "-W - only generate WUI case images"
echo "-Y - generate SMV and WUI case images"
exit
}

# --------------------- is_file_installed -----------------------------

is_file_installed()
{
  program=$1
  notfound=`$program -help 2>&1 | tail -1 | grep "not found" | wc -l`
  if [ "$notfound" == "1" ] ; then
    echo "The program $SMV is not available. Run aborted."
    exit
  fi
}

# --------------------- erase_helpinfo_files ----------------------------

erase_helpinfo_files()
{
  dir=$1

  cd $dir
  rm -f *.png
  rm -f *.help

  rm -f smokeview.version
  rm -f smokediff.version
  rm -f smokezip.version
  rm -f background.version
  rm -f wind2fds.version

  rm -f smokeview.help
  rm -f smokediff.help
  rm -f smokezip.help
  rm -f background.help
  rm -f wind2fds.help
  rm -f cfastbot.help
  rm -f firebot.help
  rm -f smokebot.help
}


# --------------------- make_helpinfo_files ----------------------------

make_helpinfo_files()
{
  dir=$1

  cd $dir

  $SMV        -help_all > smokeview.help
  $SMOKEZIP   -help     > smokezip.help
  $SMOKEDIFF  -help     > smokediff.help
  $BACKGROUND -help     > background.help
  $WIND2FDS   -help     > wind2fds.help
  $CFASTBOT   -H        > cfastbot.help
  $FIREBOT    -H        > firebot.help
  $SMOKEBOT   -H        > smokebot.help

  $SMV -version        > smokeview.version
  $SMOKEZIP -v         > smokezip.version
  $SMOKEDIFF -v        > smokediff.version
  $BACKGROUND -version > background.version
  $WIND2FDS            > wind2fds.version
}

# ---------------------------------------------------------------------------
# --------------------- beginning of script ---------------------------------
# ---------------------------------------------------------------------------

OS=`uname`
if [ "$OS" == "Darwin" ]; then
  PLATFORM=osx
else
  PLATFORM=linux
fi

COMPILER=intel
DEBUG=
TEST=
use_installed=
RUN_SMV=1
RUN_WUI=1
QUEUE=batch

while getopts 'Cdghij:q:tWY' OPTION
do
case $OPTION  in
  C)
   COMPILER=gnu
   ;;
  d)
   DEBUG=_db
   ;;
  h)
   usage;
   ;;
  i)
   use_installed="-i"
   ;;
  j)
   JOBPREFIX="$OPTARG" 
   ;;
  q)
   QUEUE="$OPTARG" 
   ;;
  t)
   TEST=_test
  ;;
  W)
   RUN_SMV=0
   RUN_WUI=1
   ;;
  Y)
   RUN_SMV=1
   RUN_WUI=1
   ;;
esac
done
shift $(($OPTIND-1))

if [ "$JOBPREFIX" == "" ]; then
  JOBPREFIX=SMV_
fi

VERSION=$PLATFORM${TEST}_64$DEBUG
VERSION2=${PLATFORM}_64
CURDIR=`pwd`
cd ../../..
export SVNROOT=`pwd`
cd $CURDIR/..
export BASEDIR=`pwd`

if [ "$QUEUE" == "none" ]; then
  PREFIX=i
  FDSEXE=$SVNROOT/fds/Build/${PREFIX}mpi_${COMPILER}_$PLATFORM/fds_${PREFIX}mpi_${COMPILER}_$PLATFORM
  if [ ! -e $FDSEXE ]; then
    PREFIX=o  
    FDSEXE=$SVNROOT/fds/Build/${PREFIX}mpi_${COMPILER}_$PLATFORM/fds_${PREFIX}mpi_${COMPILER}_$PLATFORM
  fi
  if [ -e $FDSEXE ]; then
    echo "" | $FDSEXE 2> $SVNROOT/smv/Manuals/SMV_User_Guide/SCRIPT_FIGURES/fds.version
  else
    echo "FDS version: unknown" $SVNROOT/smv/Manuals/SMV_User_Guide/SCRIPT_FIGURES/fds.version
  fi
fi

if [ "$use_installed" == "1" ] ; then
  export SMV=smokeview
  export SMOKEZIP=smokediff
  export SMOKEDIFF=smokediff
  export WIND2FDS=wind2fds
  export BACKGROUND=background
  export SMVBINDIR=`which smokeview`
  if [ "$SMVBINDIR" != "" ]; then
    SMVBINDIR=${SMVBINDIR%/*}
  fi
else
  export SMV=$SVNROOT/smv/Build/smokeview/${COMPILER}_$VERSION2/smokeview_$VERSION
  export SMOKEZIP=$SVNROOT/smv/Build/smokezip/${COMPILER}_$VERSION2/smokezip_$VERSION2
  export SMOKEDIFF=$SVNROOT/smv/Build/smokediff/${COMPILER}_$VERSION2/smokediff_$VERSION2
  export WIND2FDS=$SVNROOT/smv/Build/wind2fds/${COMPILER}_$VERSION2/wind2fds_$VERSION2
  export BACKGROUND=$SVNROOT/smv/Build/background/${COMPILER}_$VERSION2/background_$VERSION2
  export SMVBINDIR=$SVNROOT/bot/Bundlebot/smv/for_bundle
fi

SMOKEBOT=$SVNROOT/bot/Smokebot/run_smokebot.sh
FIREBOT=$SVNROOT/bot/Firebot/run_firebot.sh
CFASTBOT=$SVNROOT/bot/Cfastbot/run_cfastbot.sh

echo Generating smokeview images using:
echo background: $BACKGROUND
echo smokediff : $SMOKEDIFF
echo smokeview : $SMV
echo smokezip  : $SMOKEZIP
echo

if [ "$QUEUE" == "none" ]; then
  RUNSMV="$SVNROOT/smv/Utilities/Scripts/runsmv.sh"
else
  RUNSMV="$SVNROOT/smv/Utilities/Scripts/qsmv.sh -j $JOBPREFIX $use_installed -q $QUEUE"
fi
export QFDS=$RUNSMV
export RUNCFAST=$RUNSMV

export FDSUG=$SVNROOT/fds/Manuals/FDS_User_Guide
export SMVUG=$SVNROOT/smv/Manuals/SMV_User_Guide
export SMVVG=$SVNROOT/smv/Manuals/SMV_Verification_Guide
SUMMARY=$SVNROOT/smv/Manuals/SMV_Summary

is_file_installed $SMV
is_file_installed $SMOKEZIP
is_file_installed $SMOKEDIFF
is_file_installed $BACKGROUND
is_file_installed $WIND2FDS

erase_helpinfo_files $SMVUG/SCRIPT_FIGURES

rm -f $SUMMARY/images/*.png

cd $SMVVG/SCRIPT_FIGURES
rm -f *.version
rm -f *.png

make_helpinfo_files $SMVUG/SCRIPT_FIGURES

$SMV -version > smokeview.version

if [ "$RUN_SMV" == "1" ]; then

# precompute FED slices
  cd $SVNROOT/smv/Verification
  if [ "$QUEUE" == "none" ]; then
    $QFDS -d Visualization plume5c
  else
    $QFDS -f -d Visualization plume5c
  fi
  $QFDS -f -d Visualization plume5cdelta
  $QFDS -f -d Visualization thouse5
  $QFDS -f -d Visualization thouse5delta

  wait_cases_end

# compute isosurface from particles

  cd $SVNROOT/smv/Verification/Visualization
  echo Compressing sphere_propanec case
  $SMOKEZIP sphere_propanec

# compute isosurface from particles

  cd $SVNROOT/smv/Verification/Visualization
  echo Converting particles to isosurfaces in case plumeiso
  $SMOKEZIP -f -part2iso plumeiso

  cd $SVNROOT/smv/Verification/WUI
  echo Converting particles to isosurfaces in case pine_tree
  if  [ -e pine_tree.smv ]; then
    $SMOKEZIP -f -part2iso pine_tree
  fi

# difference plume5c and thouse5

  cd $SVNROOT/smv/Verification/Visualization
  echo Differencing cases plume5c and plume5cdelta
  $SMOKEDIFF -w -r plume5c plume5cdelta
  echo Differencing cases thouse5 and thouse5delta
  $SMOKEDIFF -w -r thouse5 thouse5delta

  echo Generating images

  cd $SVNROOT/smv/Verification
  scripts/SMV_Cases.sh
  scripts/RESTART_Cases.sh
  cd $SVNROOT/smv/Verification
  scripts/SMV_DIFF_Cases.sh
  cd $CURDIDR

fi

# generate geometry images

if [ "$RUN_WUI" == "1" ] ; then
  cd $SVNROOT/smv/Verification
  scripts/WUI_Cases.sh
fi

wait_cases_end

# copy generated images to web summary directory

cp $SMVUG/SCRIPT_FIGURES/*.png $SUMMARY/images/.
cp $SMVVG/SCRIPT_FIGURES/*.png $SUMMARY/images/.
