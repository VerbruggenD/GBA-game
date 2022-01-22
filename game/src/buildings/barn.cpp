#include <libgba-sprite-engine/background/text_stream.h>

#include "barn.h"

Barn::Barn(unsigned char azCode, unsigned char seeds, unsigned char crops) {
    this->seeds = seeds;
    this->crops = crops;
    this->azCode = azCode;
}
