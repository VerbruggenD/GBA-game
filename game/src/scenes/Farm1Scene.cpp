#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "Farm1Scene.h"

#include "../background.h"
#include "../farmer/farmer_player.h"
//#include "../farmer/farmer.h" // temp for shared palette
#include "../shared.h"
#include "../field/field.h"

std::vector<Background *> Farm1Scene::backgrounds() {
    return {
        bg.get()
    };
}

std::vector<Sprite *> Farm1Scene::sprites() {
    return {
        farmer1->getSprite(),
        field1->crop->getSprite(),
        field2->crop->getSprite(),
        field3->crop->getSprite(),
        field4->crop->getSprite(),
        // field5->crop->getSprite(),
        // field6->crop->getSprite(),
        // field7->crop->getSprite(),
        // field8->crop->getSprite(),
        // field9->crop->getSprite(),
        // field10->crop->getSprite(),
        // field11->crop->getSprite(),
        // field12->crop->getSprite()
    };

}

void Farm1Scene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));
    
    farmer1 = (new Farmer(builder, START_INDEX, boundaryMap));

    field1 = (new Field());
    field2 = (new Field());
    field3 = (new Field());
    field4 = (new Field());
    // field5 = (new Field());
    // field6 = (new Field());
    // field7 = (new Field());
    // field8 = (new Field());
    // field9 = (new Field());
    // field10 = (new Field());
    // field11 = (new Field());
    // field12 = (new Field());

    // field1->buildCrop(16, 72);
    // field2->buildCrop(48, 72);
    // field3->buildCrop(16, 104);
    // field4->buildCrop(48, 104);
    field1->buildCrop(88, 72);
    field2->buildCrop(120, 72);
    field3->buildCrop(88, 104);
    field4->buildCrop(120, 104);
    // field9->buildCrop(160, 72);
    // field10->buildCrop(192, 72);
    // field11->buildCrop(160, 104);
    // field12->buildCrop(192, 104);

    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;    // Only these windows active
    bg = std::unique_ptr<Background>(new Background(1, backgroundTiles, sizeof(backgroundTiles), backgroundMap, sizeof(backgroundMap)));
    bg.get()->useMapScreenBlock(26);

    engine->getTimer()->start();
}

void Farm1Scene::tick(u16 keys) {

    if (keys & KEY_A) {
        switch (boundaryMap[farmer1->getTile()])
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            field1->updateField();
            field2->updateField();
            field3->updateField();
            field4->updateField();
            break;
        case 10:
            field1->action(SOWN);
            break;
        case 11:
            field2->action(SOWN);
            break;
        case 12:
            field3->action(SOWN);
            break;
        case 13:
            field4->action(SOWN);
            break;        
        default:
            break;
        }
        for (size_t i = 0; i < 40000; i++){
            if (i==1){
                TextStream::instance().setText("", 9, 4);
            }
        }
    }

    farmer1->move(keys);
}