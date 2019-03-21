#include <stdio.h>
#include"debug_tools.h"


int main(int argc, char**argv)
{
    printf("%s\n", Debug_ValuesToMacro(APPLE));
    printf("%s\n", Debug_ValuesToMacro(ORANGE));
    printf("%s\n", Debug_ValuesToMacro(PEAR));
    printf("%s\n", Debug_ValuesToMacro(PEACH));
    printf("%s\n", Debug_ValuesToMacro(KIWI));
    
    return 0;
}