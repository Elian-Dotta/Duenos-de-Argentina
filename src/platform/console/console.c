#include "../../../include/platform/console/console.h"

static tError consoleInitSystem(tGame *game)
{
    return OK;
}

static tError consoleGetInput(tGame *game)
{
    return OK;
}

static tError consoleUpdate(tGame *game)
{
    return OK;
}

static tError consoleRender(tGame *game)
{
    return OK;
}

static tError consoleEndSystem(tGame *game)
{
    return OK;
}

tPlatform console = {
    consoleInitSystem,
    consoleGetInput,
    consoleUpdate,
    consoleRender,
    consoleEndSystem,
};




