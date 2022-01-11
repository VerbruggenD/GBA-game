
#include <libgba-sprite-engine/gba_engine.h>
#include <vector>

#include "farmer_player.h"
#include "farmer.h"

Farmer::Farmer(SpriteBuilder<Sprite> builder, int x, int y) {
    this->spriteFarmer = builder
        .withSize(SIZE_16_16)
        .withLocation(x, y)
        .withData(farmerTiles, sizeof(farmerTiles))
        .withinBounds()
        .buildPtr();
}

int Farmer::getOrientation() {

    spriteFarmer->animateToFrame(0);

    if (!(this->flipped) && (this->spriteFarmer->getCurrentFrame()<3)) {
        return FACING_UP;
    }
    else if (!(this->flipped) && !(this->spriteFarmer->getCurrentFrame()<3))
    {
        return FACING_RIGHT;
    }
    else if ((this->flipped) && (this->spriteFarmer->getCurrentFrame()<3))
    {
        return FACING_DOWN;
    }
    else
    {
        return FACING_LEFT;
    }
}

void Farmer::move(u16 keys) {
    spriteFarmer->flipHorizontally(0);
    spriteFarmer->flipVertically(0);

    //spriteFarmer->animateToFrame(3);

    // if (keys & KEY_ANY) {
    //     spriteFarmer -> animate();
    // }
    // else {
    //     spriteFarmer -> animateToFrame(STATIC_FRAME);
    // }

    // if (keys & KEY_ANY) {

    //     this->farmerPosX = spriteFarmer->getX();
    //     this->farmerPosY = spriteFarmer->getY();

    //     spriteFarmer -> animate();
    //     switch (keys)
    //     {
    //     case KEY_LEFT:
    //         if (!(this->facingRight)) {
    //             spriteFarmer -> animateToFrame(STATIC_FRAME);
    //             spriteFarmer->flipHorizontally(0);
    //         }
    //         break;
    //     case KEY_RIGHT:
            
    //         break;
    //     case KEY_UP:
            
    //         break;
    //     case KEY_DOWN:
            
    //         break;
        
    //     default:
    //         break;
    //     }
    // }
}