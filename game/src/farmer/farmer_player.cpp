
#include <libgba-sprite-engine/gba_engine.h>
#include <vector>

#include "farmer_player.h"
#include "farmer.h"

Farmer::Farmer(SpriteBuilder<Sprite> builder, unsigned short mapIndex, const unsigned short *mapLayout) {
    int x = this->getXcor(mapIndex);
    int y = this->getYcor(mapIndex);
    this->spriteFarmer = builder
        .withSize(SIZE_16_16)
        .withLocation(x, y)
        .withData(farmerTiles, sizeof(farmerTiles))
        .withinBounds()
        .buildPtr();
    this->mapLayout = mapLayout;
}

int Farmer::getXcor(unsigned short mapIndex) {      // tested & works
    return ((mapIndex%(this->layoutWidth+2))*8);
}

int Farmer::getYcor(unsigned short mapIndex) {      // tested & works
    return ((mapIndex/(this->layoutWidth+2))*8);
}

unsigned short Farmer::readMap(unsigned short mapIndex) {
    return (this->mapLayout[mapIndex]);
}

int Farmer::getOrientation() {                  // tested & works

    //spriteFarmer->animateToFrame(0);  // for testing

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

unsigned short Farmer::getTile() {
    auto mapX = this->farmerPosX/8;
    auto mapY = this->farmerPosY/8;
    return ((mapY*(layoutWidth+2))+mapX);
}

unsigned char Farmer::getNextTile() {
    
}

int Farmer::getMapIndex(unsigned short currentIndex, unsigned char moveCmd) {       
    auto actualWidth = this->layoutWidth+2;
    switch (moveCmd)
    {
    case FACING_UP:
        return currentIndex-(actualWidth);
        break;
    case FACING_RIGHT:
        return currentIndex+1;
        break;
    case FACING_DOWN:
        return currentIndex+(actualWidth);
        break;
    case FACING_LEFT:
        return currentIndex-1;
        break;
    
    default:
        return -1;
        break;
    }
}

void Farmer::rotate(int direction) {
    switch (direction)
    {
    case FACING_UP:
        this->flipped = 0;
        this->spriteFarmer->animateToFrame(1);
        break;
    case FACING_RIGHT:
        this->flipped = 0;
        this->spriteFarmer->animateToFrame(4);
        break;
    case FACING_DOWN:
        this->flipped = 1;
        this->spriteFarmer->animateToFrame(1);
        break;
    case FACING_LEFT:
        this->flipped = 1;
        this->spriteFarmer->animateToFrame(4);
        break;
    
    default:
        break;
    }
    this->spriteFarmer->flipHorizontally(flipped);
    this->spriteFarmer->flipVertically(flipped);
}

void Farmer::move(u16 keys) {       // when rotating the key is pressed to long, move function is also ran

    if (keys & KEY_ANY) {

        this->farmerPosX = spriteFarmer->getX();
        this->farmerPosY = spriteFarmer->getY();

        switch (keys)
        {
        case KEY_LEFT:
            if (this->getOrientation() == FACING_LEFT) {
                // check boundary map
                // move left 1 tile
                if (this->readMap(this->getTile())) {
                    //this->spriteFarmer->animateToFrame(3);
                    this->staticFrame = 4;
                    this->spriteFarmer->setVelocity(-1,0);
                }
                else {
                    this->spriteFarmer->setVelocity(0,0);
                    break;
                }
            }
            else this->rotate(FACING_LEFT);
            break;
        case KEY_RIGHT:
            if (this->getOrientation() == FACING_RIGHT) {
                // check boundary map
                // move right 1 tile
                if (this->readMap(this->getTile())) {
                    //this->spriteFarmer->animateToFrame(3);
                    this->staticFrame = 4;
                    this->spriteFarmer->setVelocity(1,0);
                }
                else {
                    this->spriteFarmer->setVelocity(0,0);
                    break;
                }              
            }
            else this->rotate(FACING_RIGHT);
            break;
        case KEY_UP:
            if (this->getOrientation() == FACING_UP) {
                // check boundary map
                // move up 1 tile
                if (this->readMap(this->getTile())) {
                    //this->spriteFarmer->animateToFrame(2);
                    this->staticFrame = 1;
                    this->spriteFarmer->setVelocity(0,-1);
                }
                else {
                    this->spriteFarmer->setVelocity(0,0);
                    break;
                }
                
            }
            else this->rotate(FACING_UP);
            break;
        case KEY_DOWN:
            if (this->getOrientation() == FACING_DOWN) {
                // check boundary map
                // move down 1 tile
                if (this->readMap(this->getTile())) {
                    //this->spriteFarmer->animateToFrame(2);
                    this->staticFrame = 1;
                    this->spriteFarmer->setVelocity(0,1);
                }
                else {
                    this->spriteFarmer->setVelocity(0,0);
                    break;
                }               
            }
            else this->rotate(FACING_DOWN);
            break;
        
        default:
            break;
        }
    }
    else {
        this->spriteFarmer->setVelocity(0,0);
    }
}