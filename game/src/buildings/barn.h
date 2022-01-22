#ifndef GBA_GAME_BUILDING_BARN
#define GBA_GAME_BUILDING_BARN

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>

#include "building.h"

class Barn : public Building {
private:
    unsigned char seeds;
    unsigned char crops;
    bool barnActivated = 0;

public:
    void nightUpdate();

    Barn(unsigned char azCode, unsigned char seeds, unsigned char crop);
};

#endif //GBA_GAME_BUILDING_BARN