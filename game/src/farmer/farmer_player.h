#ifndef GBA_GAME_FARMER_PLAYER_H
#define GBA_GAME_FARMER_PLAYER_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_types.h>
#include <libgba-sprite-engine/gba_engine.h>

#define STATIC_FRAME 0
#define FACING_UP 0
#define FACING_RIGHT 1
#define FACING_DOWN 2
#define FACING_LEFT 3

#define NO_WALK 0
#define WALK 1
#define ACTIVATION_ZONE 2

class Farmer {
private:
    unsigned char farmerPosX;
    unsigned char farmerPosY;
    bool moving;
    bool flipped;
    unsigned char staticFrame;

    const unsigned short* mapLayout;
    const unsigned char layoutWidth = 30;   // 32 tiles with last 2 unused
    const unsigned char layoutHeight = 20;  // 32 tiles with last 12 unused     // variable not used at this moment
    unsigned short mapIndex;

public:

    std::unique_ptr<Sprite> spriteFarmer;
    Sprite * getSprite() const {return spriteFarmer.get();}

    // void buySeed(u16 input, unsigned int money, unsigned char seeds);
    // void plantSeed(u16 input, unsigned char seeds);
    // void harvestCrop(u16 input, unsigned char crops);
    // void sellCrop(u16 input, unsigned char crops);
    // void getWater(u16 input, bool water);
    // void waterCrop(u16 input, bool water);

    void move(u16 input);
    int getOrientation();
    void rotate(int direction);
    int getMapIndex(unsigned short currentIndex, unsigned char moveCmd);    // simple implementation, doesnt look at the bounderies
    // unwanted behaviour possible on the edge of the map
    // easy fix, check if pos is on left or top of the map
    int getXcor(unsigned short mapIndex);
    int getYcor(unsigned short mapIndex);
    unsigned short readMap(unsigned short mapIndex);
    unsigned short getTile();
    unsigned short getNextTile(unsigned char direction);

    Farmer(SpriteBuilder<Sprite> builder, unsigned short mapIndex, const unsigned short *mapLayout);
};

#endif //GBA_GAME_FARMER_PLAYER_H