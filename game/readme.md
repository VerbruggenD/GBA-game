# FarmCity

This game is developed for the gameboy advance using the sprite engine of Wouter Groeneveld.
https://github.com/wgroeneveld/gba-sprite-engine

## Idea
The idea of this game is a farm simulation where you can buy and sell produce to farm, and ultimately earn money to expand your farming business. With expandebility in mind we created this game, but because of lack of time only a few features could be implemented.

### Possibilities we imagined
* To be able to buy seeds
* To be able to sell harvested crops
* To be able have multiple farm lands
* To be able to water your crops
* To have the option to plant different crops
* To have a nightly tax fee, to make progression more difficult

## Game model

Starting out you can choose to start a new game, after which you are dropped straight into the farm. In the farm you have a barn, a watertower, a house and 12 fields.
To select your farming tool you can go to the barn.
To water the crops you can go to the watertower.
To go to sleep you can go to the house.
All the tools from the barn can be used on the different fields.

We made the game dynamically to be able to upgrade it in a future revision. For example, we included an actionzone for a truck to be able to go to the market and sell your harvested crops or buy new seeds.


![structure diagram](https://raw.githubusercontent.com/VerbruggenD/GBA-game/master/game/img/diagram.png)

 
## Backgrounds
![background](https://github.com/VerbruggenD/GBA-game/raw/master/game/img/background.png)

For our game we only needed one background, the farm itself.
We created this background from scratch and used grit to convert it to pixeldata. Grit was really difficult and frustrating to work with but eventually after a lot of sweat and tears we got it working properly. The issues we had with the background generation:
* The tile reduction doesn't work properly which means we have a lot of tiles who are exactly the same, thats why are screenmapblock is 24 to make room for those tiles.

## Sprites

Our farmer sprite was also built from scratch and converted to pixeldata with grit, unfortunatly even after a lot, tears and blood, our farmer still has the wrong colors after converting it in grit with a shared palette. We where able to generate a single sprite with the right palette, only with wingrit and png2gba (which do not have shared palette options). An easy fix is the palette offset variables to merge them together manually, this is not currently implemented.

### Screenshot from the game

![in game menu](https://github.com/VerbruggenD/GBA-game/raw/master/game/img/screen_menu.png)

![gameplay](https://github.com/VerbruggenD/GBA-game/raw/master/game/img/screen_gameplay.png)

## Features in the game

We Implemented the most common features of a real farm, these include: 
* Planting seeds
* Watering crops
* Harvesting crops
* Changing farmtool

## Fixes (not implemented)
* Adding an empty frame to crops, for the problem with animateToFrame(0);
* The option to water crops, preventing to grow without
* Making the menu dynamically, tried it but is tricky with the implementation of TextStream. Fix, new function to convert ascii vallues yourself with const char*
* Manually making the shared palette using the palette range options in wingrit