#include "../../../include/platform/console/menu.h"

char menuC(const char* msg, const char *opt, int err, const char *errMsg)
{
    int first = 1;
    char op;

    if(!msg || !opt)
        return '\0';

    do
    {
        if(!first && err && errMsg)
        {
            printf("%s", errMsg);
        }

        printf("%s", msg);

        scanf(" %c", op);

    }while(!strchr(msg, op));

    return op;
}

int menuN(const char* msg, int amountOptions, int err, const char *errMsg)
{
    int first = 1;
    int op;

    if(!msg || !amountOptions)
        return '\0';

    do
    {
        if(!first && err && errMsg)
        {
            printf("%s", errMsg);
        }

        printf("%s", msg);

        scanf("%d", op);

    }while(op < 0 || op > amountOptions);

    return op;    
}