# FarmCity

https://github.com/wgroeneveld/gba-sprite-engine


#### Game model

Starting out you can choose to start a new game, after which you are dropped straight into the farm. In the farm you have a barn, a watertower, a house and 12 fields.
To select your farming tool you can go to the barn.
To water the crops you can go to the watertower.
To go to sleep you can go to the house.
All the tools from the barn can be used on the different fields.

We made the game dynamically to be able to upgrade it in a future revision. For example, we included an actionzone for a truck to be able to go to the market and sell your harvested crops or buy new seeds.


![structure diagram](https://raw.githubusercontent.com/VerbruggenD/GBA-game/game_base_restructure/game/img/diagram.png)

 
#### Backgrounds

For our game we only needed one background, the farm itself.
We created this background from scratch and used grit to convert it to pixeldata. Grit was really difficult and frustrating to work with but eventually after a lot of sweat and tears we got it working properly. 

#### Sprites

Our farmer sprite was also built from scratch and converted to pixeldata with grit, unfortunatly even after a lot, tears and blood, our farmer still has the wrong colors after converting it in grit with a shared palette.

### Screenshot from the game

![background](https://github.com/VerbruggenD/GBA-game/raw/game_base_restructure/game/img/background.png)

![in game menu](https://github.com/VerbruggenD/GBA-game/raw/game_base_restructure/game/img/background.png)

### Features in the game

We Implemented the most common features of a real farm, these include: 
* Planting seeds
* Watering crops
* Harvesting crops
* Changing farmtool