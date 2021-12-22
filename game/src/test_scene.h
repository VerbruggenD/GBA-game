

#ifndef GBA_SPRITE_ENGINE_FIRST_TEST_SCENE_H
#define GBA_SPRITE_ENGINE_FIRST_TEST_SCENE_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/background/background.h>

class FirstTestScene : public Scene {
private:
    std::unique_ptr<Sprite> animation;
    std::unique_ptr<Background> bg;
    bool pressingAorB = false;

public:
    FirstTestScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_FIRST_TEST_SCENE_H
