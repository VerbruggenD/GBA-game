#ifndef GBA_GAME_BUILDING_BARN
#define GBA_GAME_BUILDING_BARN

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>

#include "building.h"

#define MENU_COL 5
#define MENU_ROW_1 5
#define MENU_ROW_2 8
#define MENU_ROW_3 11
#define MENU_ROW_4 14

class Barn : public Building {
protected:

private:
    unsigned char seeds;
    unsigned char crops;
    bool barnActivated = 0;

public:
    void nightUpdate();

    void enter() override;
    void exit() override;

    Barn(unsigned char seeds, unsigned char crop);
};

#endif //GBA_GAME_BUILDING_BARN