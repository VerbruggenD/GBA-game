#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "SplashScene.h"
#include "Farm1Scene.h"

#include "../Startscreen.h"
//#include "shared.h"

std::vector<Background *> SplashScene::backgrounds() {
    return {
        bg.get()
    };
}

std::vector<Sprite *> SplashScene::sprites() {
    return {};
}

void SplashScene::load() {

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(StartscreenPal, sizeof(StartscreenPal)));

    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;    // Only these windows active
    bg = std::unique_ptr<Background>(new Background(1, StartscreenTiles, sizeof(StartscreenTiles), StartscreenMap, sizeof(StartscreenMap)));
    bg.get()->useMapScreenBlock(26);
    TextStream::instance().setText("   > New Game             ", 9, 6);
}

 void SplashScene::tick(u16 keys) {
    if (keys & KEY_ANY) {
        for (size_t i = 0; i < 80000; i++){
            if (i==1){
                TextStream::instance().setText("entered: starting farm", 9, 4);
            }
        }
        engine->setScene(new Farm1Scene(engine));
    }
}