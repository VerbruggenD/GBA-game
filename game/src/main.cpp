#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>

#include "SplashScene.h"

int main() {
     std::shared_ptr<GBAEngine> engine(new GBAEngine());

     SplashScene* splash = new SplashScene(engine);
     engine->setScene(splash);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}