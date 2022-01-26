#ifndef GBA_SPRITE_ENGINE_SPLASH
#define GBA_SPRITE_ENGINE_SPLASH

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/background/background.h>

class SplashScene : public Scene {
private:

public:
    SplashScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    std::vector<Background *> backgrounds() override;
    std::vector<Sprite *> sprites() override;

    void load() override;
    void tick(u16 keys) override;

};
#endif //GBA_SPRITE_ENGINE_SPLASH