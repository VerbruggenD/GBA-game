#include "field.h"

char Field::whichCrop(){
    if (status)
    {
        return crop->whichCrop;
    }
    return NULL;
};

void Field::updateField(){
    if (water)
    {
        if (status<3)
        {
            status++;
        }
    }
};

void Field::plant(char whichCrop, int x, int y){
    if (!status)
    {
        
        Crop* crop = new Crop(builder,, x, y);
        crop->whichCrop = whichCrop;
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