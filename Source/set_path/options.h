#ifndef OPTIONS_H_DEFINED
#define OPTIONS_H_DEFINED

#include "options_common.h"

//*** uncomment the following two lines to force all versions to be beta
//#undef pp_BETA
//#define pp_BETA

int reg_path(int setget, int pathtype, char *path);
#define REG_GET 0
#define REG_SET 1
#define REG_USER_PATH 2
#define REG_SYSTEM_PATH 3

#endif
