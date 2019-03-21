#include"debug_tools.h"

/***********************************************************************************
Copy right: 2018-2028 USR IOT Tech.
Author:     Qigan Chen
Version:    V1.0
Date:       2018-12
Description: Used to print macro definition names
***********************************************************************************/
char* Debug_ValuesToMacro(int value)
{
    switch(value){
        
        SWITCH_UNIT(APPLE);
        SWITCH_UNIT(ORANGE);
        SWITCH_UNIT(PEAR);
        SWITCH_UNIT(PEACH);
        SWITCH_UNIT(KIWI);
    }
}

