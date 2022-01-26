#include <libgba-sprite-engine/background/text_stream.h>

#include "barn.h"
#include "building.h"

Barn::Barn(unsigned char seeds, unsigned char crops) {
    this->seeds = seeds;
    this->crops = crops;
}

void Barn::enter() {
    // vervangen door generic menu class
    this->barnActivated = true;
    TextStream::instance().setText("Crops: " + std::to_string(this->crops), MENU_ROW_1, MENU_COL_1);
    TextStream::instance().setText("Seeds: " + std::to_string(this->seeds),MENU_ROW_2, MENU_COL_1);
}

void Barn::exit() {}