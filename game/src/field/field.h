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
    char water = 0;

    SpriteBuilder<Sprite> builder;

public:
    char whichCrop();
    void updateField();
    void plant(char whichCrop, int x, int y);
    void harvest();
    Crop* crop;
};

#endif