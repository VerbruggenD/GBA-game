
#include <libgba-sprite-engine/gba_engine.h>
#include <vector>

#include "farmer_player.h"
#include "farmer.h"

Farmer::Farmer(SpriteBuilder<Sprite> builder, int x, int y, unsigned int money, unsigned char seeds, bool water, unsigned char crops) {
    this->spriteFarmer = builder
        .withSize(SIZE_16_16)
        .withLocation(x, y)
        .withData(farmerTiles, sizeof(farmerTiles))
        .withinBounds()
        .buildPtr();
}

// void Farmer::buySeed(u16 input, unsigned int money, unsigned char seeds) {

// }