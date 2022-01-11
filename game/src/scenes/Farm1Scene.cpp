#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "Farm1Scene.h"

#include "../background.h"
#include "../farmer/farmer_player.h"
#include "../farmer/farmer.h" // temp for shared palette
//#include "shared.h"

std::vector<Background *> Farm1Scene::backgrounds() {
    return {
        bg.get()
    };
}

std::vector<Sprite *> Farm1Scene::sprites() {
    return {
        farmer1->getSprite()
    };

}

void Farm1Scene::load() {

    //engine.get()->disableText();
    //engine.get()->enableText();

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(farmerPal, sizeof(farmerPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));
    
    farmer1 = (new Farmer(builder, START_INDEX, boundaryMap));

    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;    // Only these windows active
    //bg = std::unique_ptr<Background>(new Background(0, backgroundTiles, sizeof(backgroundTiles), backgroundMap, sizeof(backgroundMap)));
    bg = std::unique_ptr<Background>(new Background(1, backgroundTiles, sizeof(backgroundTiles), backgroundMap, sizeof(backgroundMap)));
    bg.get()->useMapScreenBlock(26);

    //TextStream::instance().clear();
    //TextStream::instance().setText("test", 10, 10);

    engine->getTimer()->start();
}

void Farm1Scene::tick(u16 keys) {
    //TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);
    //TextStream::instance().clear();

    //  int test = farmer1->getOrientation();      // testing of function getOrientation
    //  TextStream::instance().setText(std::to_string(test),10,10);

    // auto test = boundaryMap[0];     // test inlezen boundary map
    // TextStream::instance().setText(std::to_string(test),10,10);

    // auto test = farmer1->readMap(farmer1->getTile());
    // TextStream::instance().setText(std::to_string(test),10,10);

    farmer1->move(keys);
}