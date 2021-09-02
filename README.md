# 1337 Coding Scool (42 Network)

## Wolf3d

This project is a 3D graphically “realistic” representation that we could have
from inside a maze in a subjective view. This representation uses the
Ray-Casting, and my first interaction with SDL2 libraries.

[![previewg_gif](resources/screenshots/home.JPG)](https://youtu.be/Ao9eQynjYZE)

### Requirements

* The management of your window must remain smooth: passing over of another
window, minimization, etc.
* Pressing ESC must close the window and quit the program cleanly.
* Clicking on the red cross on the window’s frame must close the window
and quit the program cleanly.
* The arrows on the keyboard must allow you to move in real time in the maze,
like in the original game.
* The wall’s colors must vary depending on the direction
(North, South, East, West).
* Wall collisions
* A skybox
* Floor and/or ceiling texture

## Getting Started

### Compiling

Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and binary file (program):
	- `make fclean`

<img src="resources/screenshots/makefile.JPG" width="400" />

* To re-compile:
	- `make re`

<img src="resources/screenshots/makefile2.JPG" width="400" />

### Executing

To run the program:

`./wolf3d`

## Screenshots

# Home 
<img src="resources/screenshots/home.JPG" width="1280" />

# Select Texture
<img src="resources/screenshots/texture.JPG" width="1280" />

# First Wall Texture 
<img src="resources/screenshots/map1.JPG" width="1280" />

# Second Wall Texture 
<img src="resources/screenshots/map2.JPG" width="1280" />

# Third Wall Texture 
<img src="resources/screenshots/map3.JPG" width="1280" />
