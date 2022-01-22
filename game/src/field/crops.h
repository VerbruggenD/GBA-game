#ifndef GBA_GAME_CROPS_H
#define GBA_GAME_CROPS_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_types.h>
#include <libgba-sprite-engine/gba_engine.h>

// include crop sprites

#define SOWN 0
#define MAIS 1
#define POTATO 2
#define WHEAT 3

class Crop {
private:
    
public:
    unsigned char whichCrop;    // which crop is planted
    Sprite * getSprite() const {return CropSprite.get();}

    std::unique_ptr<Sprite> CropSprite;
    Crop(SpriteBuilder<Sprite> builder, int x, int y, unsigned char whichCrop);
};

#endif //GBA_GAME_CROPS_H