#ifndef DEBUG_TOOLS_H
#define DEBUG_TOOLS_H

#include <stdio.h>

#define SWITCH_UNIT(T)  case T:return #T

#define APPLE        0
#define ORANGE       1 
#define PEAR         2
#define PEACH        3 
#define KIWI         4 


char* Debug_ValuesToMacro(int value);

#endif//DEBUG_TOOLS_H