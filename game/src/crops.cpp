#include "crops.h"

Crop::Crop(SpriteBuilder<Sprite> builder, std::unique_ptr<Sprite> *src, int x, int y, unsigned char whichCrop) {
    this->CropSprite = builder
        .withLocation(x,y)
        .withSize(SIZE_16_16)
        .buildWithDataOf(*src->get());
    this->whichCrop = whichCrop;
}