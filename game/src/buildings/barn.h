#ifndef GBA_GAME_BUILDING_BARN
#define GBA_GAME_BUILDING_BARN

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>

#include "building.h"

#define MENU_COL_1 2
#define MENU_ROW_1 1
#define MENU_ROW_2 3
#define MENU_COL_2 10

class Barn : public Building {
protected:

private:
    unsigned char seeds;
    unsigned char crops;
    bool barnActivated = 0;

public:
    void enter() override;
    void exit() override;

    Barn(unsigned char seeds, unsigned char crop);
};

#endif //GBA_GAME_BUILDING_BARN