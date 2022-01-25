#include <libgba-sprite-engine/background/text_stream.h>

#include "barn.h"
#include "menu.h"
#include "building.h"

Barn::Barn(unsigned char seeds, unsigned char crops) :
        menu(std::shared_ptr<Menu>(new Menu())) {
    this->seeds = seeds;
    this->crops = crops;
}

void Barn::enter() {
    menu->item1 = "test";
}

void Barn::exit() {}