#ifndef GBA_GAME_FIELD_H
#define GBA_GAME_FIELD_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_types.h>
#include <libgba-sprite-engine/gba_engine.h>

class Field {
private:
    
public:
    unsigned char whichCrop;    // which crop is planted

    std::unique_ptr<Sprite> CropSprite;
    Crop(SpriteBuilder<Sprite> builder, std::unique_ptr<Sprite> *src, int x, int y, unsigned char whichCrop);
};

#endif