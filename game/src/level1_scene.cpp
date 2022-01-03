#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "level1_scene.h"

#include "level1_bg.h"

std::vector<Background *> Level1Scene::backgrounds() {
    return {
        bg.get()
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
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(level1_bgPal, sizeof(level1_bgPal)));

    SpriteBuilder<Sprite> builder;

    // animation = builder
    //         .withData(lamaTiles, sizeof(lamaTiles))
    //         .withSize(SIZE_32_32)
    //         .withAnimated(6, 3)
    //         .withLocation(50, 50)
    //         .buildPtr();

    
    TextStream::instance().setText("TEEESST", 0, 0);

    bg = std::unique_ptr<Background>(new Background(1, level1_bgTiles, sizeof(level1_bgTiles), level1_bgMap, sizeof(level1_bgMap)));
    bg.get()->useMapScreenBlock(16);

    //TextStream::instance().setText(std::string("Portal 2.5"), 5, 8);

    engine->getTimer()->start();
}

 void Level1Scene::tick(u16 keys) {
     TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

//     if(pressingAorB && !((keys & KEY_A) || (keys & KEY_B))) {
//         engine->getTimer()->toggle();
//         pressingAorB = false;
//     }

//     if(keys & KEY_START) {
//         if(!engine->isTransitioning()) {
//             //engine->enqueueSound(zelda_secret_16K_mono, zelda_secret_16K_mono_bytes);

//             //TextStream::instance() << "entered: starting next scene";

//             //engine->transitionIntoScene(new FlyingStuffScene(engine), new FadeOutScene(2));
//         }
//     } else if(keys & KEY_LEFT) {
//         animation->flipHorizontally(true);
//     } else if(keys & KEY_RIGHT) {
//         animation->flipHorizontally(false);
//     } else if(keys & KEY_UP) {
//         animation->flipVertically(true);
//     } else if(keys & KEY_DOWN) {
//         animation->flipVertically(false);
//     } else if((keys & KEY_A) || (keys & KEY_B)) {
//         pressingAorB = true;
//     }
}