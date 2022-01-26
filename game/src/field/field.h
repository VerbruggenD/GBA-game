#ifndef GBA_GAME_FIELD_H
#define GBA_GAME_FIELD_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_types.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "crops.h"

#define LEEG 0
#define GEPLANT 1
#define GESPROUT 2
#define VOLGROEIT 3

class Field {
private:
    char status = LEEG;
    char water = 1;

    SpriteBuilder<Sprite> builder;

public:
    char whichCrop();
    void updateField();
    void buildCrop(char x, char y);
    void plant(char whichCrop);
    void harvest();
    void action(char whichCrop);
    Crop* crop;
};

#endif