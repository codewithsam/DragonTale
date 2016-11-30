# DragonTale

A 2D Platformer game "Dragon Tale" made with C++ and SFML without the use of any game engine.

## Installation

The project requires SFML 2.x to be compiled. If you don't have it installed yet, you can follow this link or do the commands bellow :
```
- Download SFML library from http://www.sfml-dev.org/download.php or clone their git https://github.com/SFML/SFML
- Go to Visual Studio Project Properties.
- In C/C++|General in Additional Include Libraries set path of SFML include folder.
- In Linker|General in Additional Library Directory set path of SFML lib folder.
- In Linker|Input in Additional Dependencies copy/paste following dependencies sfml-audio-d.lib;sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib; if not already present.

```
## Commands

- Left and Right arrows to move dragon character
- W to Jump
- W+E to Glide
- F to Fire
- R for Slashing

## What has been done ?

* Player can walk, run, jump, fall, slash, glide
* A debug mode that displays extra information
* Loading custom maps, camera follow the player, rendering only those tiles which are shown on screen
* GameStateManager class is used to manage, load and unload all the game states
* minimalistic 2D physics
* Level stored in a 2D array. First 2 lines of file contains total amount of tiles to load and number of rows
* Collision detection
* Scrolling

## What next ?

* Death of player
* Adding enemies
* Reading of TiledMap Editor's XML file format directly for loading of maps.
* Cool new levels
* Final Boss Raid in each level
