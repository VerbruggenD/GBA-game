#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "level1_scene.h"

#include "background.h"
#include "farmer.h"
#include "shared.h"

std::vector<Background *> Level1Scene::backgrounds() {
    return {
        bg.get()
    };
}

std::vector<Sprite *> Level1Scene::sprites() {
    return {  
        farmer.get()
        };
}

void Level1Scene::load() {

    engine.get()->disableText();
    //engine.get()->enableText();

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));

    SpriteBuilder<Sprite> builder;

    farmer = builder
            .withData(farmerTiles, sizeof(farmerTiles))
            .withSize(SIZE_16_16)
            .withAnimated(3, 10)
            .withLocation(50, 50)
            .buildPtr();

    
    //TextStream::instance().setText("TEEESST", 0, 0);

    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;    // Only these windows active
    //bg = std::unique_ptr<Background>(new Background(0, backgroundTiles, sizeof(backgroundTiles), backgroundMap, sizeof(backgroundMap)));
    bg = std::unique_ptr<Background>(new Background(1, backgroundTiles, sizeof(backgroundTiles), backgroundMap, sizeof(backgroundMap)));
    bg.get()->useMapScreenBlock(26);

    

    engine->getTimer()->start();
}

 void Level1Scene::tick(u16 keys) {
     TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

}