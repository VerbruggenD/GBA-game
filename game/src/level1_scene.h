#ifndef GBA_SPRITE_ENGINE_SCENE_1
#define GBA_SPRITE_ENGINE_SCENE_1

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/background/background.h>

class Level1Scene : public Scene {
private:
    std::unique_ptr<Sprite> farmer;
    std::unique_ptr<Background> bg;
    bool pressingAorB = false;

public:
    Level1Scene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;

};
#endif //GBA_SPRITE_ENGINE_SCENE_1