#include <libgba-sprite-engine/gba_engine.h>
#include <vector>

#include "watertower.h"

#define CAPACITY 1000

void Watertower::water_crops(){
    if (water > 50)
    {
        water = water - 50;
    }
}

void Watertower::rain(){
    water = water + 100;
    if (water > CAPACITY)
    {
        water = CAPACITY;
    }
}
