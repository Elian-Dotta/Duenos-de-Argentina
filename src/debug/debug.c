#include "../../include/debug/debug.h"

tError debugMenu()
{
    int opt;

    do
    {
        opt = menuN(DEBUG_MENU, DEBUG_OPT, 0, NULL);

        switch(opt)
        {
            case LIST:
                printf("This should provide a list test\n");
                break;
            case LEAVE:
                printf("This should leave the program\n");
                break;

        }
    }while(opt != 0);

    return OK;
}
