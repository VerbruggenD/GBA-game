#ifndef GBA_GAME_FARMER_PLAYER_H
#define GBA_GAME_FARMER_PLAYER_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_types.h>
#include <libgba-sprite-engine/gba_engine.h>

class Farmer {
private:
    unsigned char farmerPosX;
    unsigned char farmerPosY;
    bool moving;
    bool facingDown;
    bool facingRight;

    // unsigned int money;
    // unsigned char seeds;
    // bool water;
    // unsigned char crops;

    // const unsigned short* mapLayout;

public:

    std::unique_ptr<Sprite> spriteFarmer;
    Sprite * getSprite() const {return spriteFarmer.get();}

    void buySeed(u16 input, unsigned int money, unsigned char seeds);
    void plantSeed(u16 input, unsigned char seeds);
    void harvestCrop(u16 input, unsigned char crops);
    void sellCrop(u16 input, unsigned char crops);
    void getWater(u16 input, bool water);
    void waterCrop(u16 input, bool water);

    void move(u16 input, int x, int y);

    Farmer(SpriteBuilder<Sprite> builder, int x, int y, 
    unsigned int money, unsigned char seeds, bool water, unsigned char crops);
};

#endif //GBA_GAME_FARMER_PLAYER_H