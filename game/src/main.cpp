#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>

#include "level1_scene.h"

/**
 * shared palette extracted from grit
 * ./../grit piskel.png piskel2.png kul.png -ftc -pS -gB8 -O shared.c
 * assumes 8bpp sprites
 */
int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    Level1Scene* scene1 = new Level1Scene(engine);
    engine->setScene(scene1);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}