#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include "../foundation/error.h"
#include "../platform/console/menu.h"

#define DEBUG_MENU "\
-----------------------------\n\
-        DEBUG MODE         -\n\
-                           -\n\
-  1 - Test SList           -\n\
-  0 - Leave                -\n\
-----------------------------\n\
\n\
> Choose an option: "

#define DEBUG_OPT 1

enum
{
    LEAVE,
    LIST
};

tError debugMenu();

#endif // DEBUG_H_INCLUDED
