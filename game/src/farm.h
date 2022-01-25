#ifndef GBA_GAME_FARM
#define GBA_GAME_FARM

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>

#include "buildings/barn.h"
#include "farmer/farmer_player.h"

#define START_INDEX 32*4

#define NO_WALK 0
#define WALK 1
#define AZ_BARN 2
#define AZ_HOME 5
#define AZ_WATERT 4

class Farm {
private:
    SpriteBuilder<Sprite> builder;
    
public:
    void nightUpdate();
    void selectZone();
    void load();
    Farmer* farmer;
    //Barn* barn;

    Farm();
};

#endif //GBA_GAME_FARM