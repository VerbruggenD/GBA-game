#ifndef GBA_SPRITE_ENGINE_SCENE_1
#define GBA_SPRITE_ENGINE_SCENE_1

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/background/background.h>

#include "../farmer/farmer_player.h"

#define START_INDEX 32*4

#define NO_WALK 0
#define WALK 1
#define AZ_BARN 2
#define AZ_HOME 5
#define AZ_WATERT 4

class Farm1Scene : public Scene{
private:
    std::unique_ptr<Background> bg;
    bool pressingAorB = false;

    SpriteBuilder<Sprite> builder;
    Farmer* farmer1;

public:
    Farm1Scene(std::shared_ptr<GBAEngine> engine) : Scene(engine){}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;
    void Farm1Scene::selectZone(auto mapKey);

};
#endif //GBA_SPRITE_ENGINE_SCENE_1