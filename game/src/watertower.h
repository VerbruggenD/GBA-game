#ifndef GBA_SPRITE_ENGINE_WATERTOWER
#define GBA_SPRITE_ENGINE_WATERTOWER

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/background/background.h>

class Watertower {

private:
int water;

public:
void water_crops();
void rain();

};

#endif  //GBA_GAME_WATERTOWER