#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "level1_scene.h"

std::vector<Background *> Level1Scene::backgrounds() {
    return {
        //bg.get()
    };
}

std::vector<Sprite *> Level1Scene::sprites() {
    return {  
        //animation.get()
        };
}

void Level1Scene::load() {

    //engine.get()->disableText();
    //engine.get()->enableText();

    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(testPal, sizeof(testPal)));
    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(level1_bgPal, sizeof(level1_bgPal)));

    SpriteBuilder<Sprite> builder;

    // animation = builder
    //         .withData(lamaTiles, sizeof(lamaTiles))
    //         .withSize(SIZE_32_32)
    //         .withAnimated(6, 3)
    //         .withLocation(50, 50)
    //         .buildPtr();

    
    TextStream::instance().setText("TEEESST", 0, 0);

    //bg = std::unique_ptr<Background>(new Background(1, level1_bgTiles, sizeof(level1_bgTiles), level1_bgMap, sizeof(level1_bgMap)));
    //bg.get()->useMapScreenBlock(16);

    engine->getTimer()->start();
}

 void Level1Scene::tick(u16 keys) {
     //TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

}