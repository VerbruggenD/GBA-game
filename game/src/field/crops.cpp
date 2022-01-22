#include "crops.h"
#include "crops_data.h"

Crop::Crop(SpriteBuilder<Sprite> builder, int x, int y, unsigned char whichCrop) {
    this->CropSprite = builder
        .withLocation(x,y)
        .withSize(SIZE_16_16)
        .withData(CropsTiles, sizeof(CropsTiles))
        .withinBounds()
        .buildPtr();
    this->whichCrop = whichCrop;
}