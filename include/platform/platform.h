#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#include "../foundation/error.h"

// FORWARD DECLARATION

typedef struct tGame tGame;

typedef tError (*tInitSystem)(tGame *game);
typedef tError (*tGetInput)(tGame *game);
typedef tError (*tUpdate)(tGame *game);
typedef tError (*tRender)(tGame *game);
typedef tError (*tEndSystem)(tGame *game);

typedef struct
{
    tInitSystem initSystem;
    tGetInput   getInput;
    tUpdate     update;
    tRender     render;
    tEndSystem  endSystem;
} tPlatform;

#endif // PLATFORM_H_INCLUDED
