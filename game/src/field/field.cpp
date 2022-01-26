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
        if (status == LEEG)
        {
            return;
        }
        else if (status == GEPLANT)
        {
            status = GESPROUT;
            crop->CropSprite->animateToFrame(GESPROUT);
        }
        else if (status == GESPROUT)
        {
            status = VOLGROEIT;
            crop->CropSprite->animateToFrame(whichCrop()+3);
        }
        
    }
};

void Field::buildCrop(char x, char y){
    crop = (new Crop(builder, x, y, 0));
    crop->CropSprite->animateToFrame(LEEG);
}

void Field::plant(char whichCrop){
    if (status == LEEG)
    {
        crop->whichCrop = whichCrop;
        crop->CropSprite->animateToFrame(GEPLANT);
        status = GEPLANT;
    }
};

void Field::harvest(){
    if (status == VOLGROEIT)
    {
        crop->CropSprite->animateToFrame(LEEG);
        status = LEEG;
    }
};

void Field::plantOrHarvest(char wichCrop){      // previously named action
    if (status==LEEG)
    {
        Field::plant(wichCrop);
    }
    else if (status==VOLGROEIT)
    {
        Field::harvest();
    }
}