#ifndef GBA_GAME_FARMER_PLAYER_H
#define GBA_GAME_FARMER_PLAYER_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_types.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>

#define STATIC_FRAME 0
#define FACING_UP 0
#define FACING_RIGHT 1
#define FACING_DOWN 2
#define FACING_LEFT 3

#define NO_TOOL 0
#define SEED 1
#define WATER 2
#define SHOVEL 3

class Farmer {
private:
    unsigned char farmerPosX;       // updated in move(), current cordinates
    unsigned char farmerPosY;
    bool moving = true;         // allowed to move
    bool flipped;               // to rotate sprite 180 degrees, flipHorizontally & Vertically
    unsigned char staticFrame;      // static frame of sprite orientation, for animated
    unsigned char toolUsing;    // can be shovel, seeds, water; getter and setter

    const unsigned short* mapLayout;    // boundary map from Scene
    const unsigned char layoutWidth = 30;   // 32 tiles with last 2 unused

public:

    std::unique_ptr<Sprite> spriteFarmer;
    Sprite* getSprite() const {return spriteFarmer.get();}

    void move(u16 input);
    int getOrientation();
    void rotate(int direction);
    int getNextTile(unsigned char moveCmd);    // simple implementation, doesnt look at the bounderies
    // unwanted behaviour possible on the edge of the map
    // easy fix, check if pos is on left or top of the map
    
    int getXcor(unsigned short mapIndex){ return ((mapIndex%(this->layoutWidth+2))*8); };
    int getYcor(unsigned short mapIndex){ return ((mapIndex/(this->layoutWidth+2))*8); };
    unsigned short readMap(unsigned short mapIndex){ return (this->mapLayout[mapIndex]); };
    
    unsigned short getTile();
    void setMoving(bool moving) {this->moving = moving;};
    void hide(bool hide);
    void setTool(unsigned char tool) {this->toolUsing = tool;};
    unsigned char getTool() {return this->toolUsing;};
    void printTool();

    Farmer(SpriteBuilder<Sprite> builder, unsigned short mapIndex, const unsigned short *mapLayout);
};

#endif //GBA_GAME_FARMER_PLAYER_H