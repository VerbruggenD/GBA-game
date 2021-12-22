// this is a test scene for the first steps of the gba project.
// 13/12/2021

#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "test_scene.h"

#include "lama.h"
#include "testbackground.h"
#include "test.h"

std::vector<Sprite *> FirstTestScene::sprites() {
    return {  animation.get()};
}

std::vector<Background *> FirstTestScene::backgrounds() {
    return {
        bg.get()
    };
}

void FirstTestScene::load() {

    //engine.get()->disableText();

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(testPal, sizeof(testPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(testbackgroundPal, sizeof(testbackgroundPal)));

    SpriteBuilder<Sprite> builder;

    animation = builder
            .withData(lamaTiles, sizeof(lamaTiles))
            .withSize(SIZE_32_32)
            .withAnimated(6, 3)
            .withLocation(50, 50)
            .buildPtr();

    //TextStream::instance().setText("PRESS START", 3, 8);

    bg = std::unique_ptr<Background>(new Background(1, testbackgroundTiles, sizeof(testbackgroundTiles), testbackgroundMap, sizeof(testbackgroundMap),16,0,0));
    bg.get()->useMapScreenBlock(16);

    engine->getTimer()->start();
}

void FirstTestScene::tick(u16 keys) {
    //TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

    if(pressingAorB && !((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
        pressingAorB = false;
    }

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            //engine->enqueueSound(zelda_secret_16K_mono, zelda_secret_16K_mono_bytes);

            //TextStream::instance() << "entered: starting next scene";

            //engine->transitionIntoScene(new FlyingStuffScene(engine), new FadeOutScene(2));
        }
    } else if(keys & KEY_LEFT) {
        animation->flipHorizontally(true);
    } else if(keys & KEY_RIGHT) {
        animation->flipHorizontally(false);
    } else if(keys & KEY_UP) {
        animation->flipVertically(true);
    } else if(keys & KEY_DOWN) {
        animation->flipVertically(false);
    } else if((keys & KEY_A) || (keys & KEY_B)) {
        pressingAorB = true;
    }
}