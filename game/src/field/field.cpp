#include "field.h"
#include "crops.h"

char Field::whichCrop(){
    if (status)
    {
        return crop->whichCrop;
    }
    return 0;
};

void Field::updateField(){
    if (water)
    {
        if (status<2)
        {
            status++;
            crop->CropSprite->animateToFrame(status+1);
        }
        else if (status == 2)
        {
            status++;
            crop->CropSprite->animateToFrame(whichCrop()+3);
        }
        
    }
};

void Field::plant(char whichCrop, int x, int y){
    if (!status)
    {
        crop = (new Crop(builder, x, y, whichCrop));
        status = GEPLANT;
    }
};

void Field::harvest(){
    if (status == 3)
    {
        delete crop;
        status = LEEG;
    }
};