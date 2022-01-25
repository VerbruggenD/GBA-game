#ifndef GBA_GAME_BUILDING_BARN
#define GBA_GAME_BUILDING_BARN

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>

#include "building.h"
#include "menu.h"

class Barn : public Building, public Menu {
protected:
    std::shared_ptr<Menu> menu;

private:
    unsigned char seeds;
    unsigned char crops;
    bool barnActivated = 0;

    Menu* showMenu();

public:
    void nightUpdate();

    void enter() override;
    void exit() override;

    Barn(unsigned char seeds, unsigned char crop);
};

#endif //GBA_GAME_BUILDING_BARN