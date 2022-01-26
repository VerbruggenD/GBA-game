#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>

#include "Farm1Scene.h"

#include "../background.h"
#include "../farmer/farmer.h" // temp for shared palette
//#include "shared.h"
//#include "../farm.h"
#include "../buildings/barn.h"

std::vector<Background *> Farm1Scene::backgrounds() {
    return {
        bg.get()
    };
}

std::vector<Sprite *> Farm1Scene::sprites() {
    return {
        farmer->getSprite()
    };

}

void Farm1Scene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(farmerPal, sizeof(farmerPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));

    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;    // Only these windows active
    bg = std::unique_ptr<Background>(new Background(1, backgroundTiles, sizeof(backgroundTiles), backgroundMap, sizeof(backgroundMap)));
    bg.get()->useMapScreenBlock(26);

    farmer = (new Farmer(builder, START_TILE, boundaryMap));
    barn = new Barn(10,10);

    //engine->getTimer()->start();
}

void Farm1Scene::tick(u16 keys) {

    if (keys & KEY_A) {
        selectZone(keys);
    }
    if (keys & KEY_B) exitZone(keys);

    farmer->move(keys);
}

void Farm1Scene::exitZone(u16 keys) {
    TextStream::instance().clear();
    farmer->setMoving(true);
    farmer->hide(false);
    bg->updateMap(backgroundMap);
}

void Farm1Scene::selectZone(u16 keys) {
    auto mapKey = farmer->readMap(farmer->getTile());
    switch (mapKey)
        {
        case AZ_BARN:
        {
            bg->updateMap(menuMap);
            farmer->setMoving(false);
            farmer->hide(true);
            barn->enter();
            break;
        }
        case AZ_HOME:
            TextStream::instance().setText("home",10,10);
            break;

        case AZ_WATERT:
            TextStream::instance().setText("watertower",10,10);
            break;
        
        default:
            TextStream::instance().clear();
            break;
        }
}