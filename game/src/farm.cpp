#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/background/background.h>

#include "farm.h"
#include "buildings/barn.h"

#include "farmer/farmer_player.h"
#include "background.h"

Farm::Farm(void) {
    Barn* barn = new Barn(0,0,0);
    farmer = (new Farmer(builder, START_INDEX, boundaryMap));
}

void Farm::load() {
    
}

void Farm::nightUpdate() {
    
}

void Farm::selectZone() {
    auto mapKey = farmer->readMap(farmer->getTile());
    switch (mapKey)
        {
        case AZ_BARN:
            TextStream::instance().setText("barn",10,10);
            break;

        case AZ_HOME:
            TextStream::instance().setText("home",10,10);
            break;

        case AZ_WATERT:
            TextStream::instance().setText("watertower",10,10);
            break;
        
        default:
            TextStream::instance().clear();
            break;
        }
}