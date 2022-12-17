# cub3D
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever.
The goal is to create a dynamic view inside a maze, in which you'll have to find your way.

Its an introduction to the concept of **ray casting**, which is the basis of many computer graphics rendering algorithms.

The usage of the graphics library MiniLibX was mandatory.

Contributers: **kamilprzybyl** and **imexz**

[Guide used for this project](https://harm-smits.github.io/42docs/projects/cub3d)

Example of a view:

<img width="638" alt="Screenshot 2022-12-17 at 10 40 38" src="https://user-images.githubusercontent.com/82594855/208235809-17e83403-dbc9-4031-b72a-de9382d86b63.png"> [^1]

## Usage
- Run `make` in the root of the repository.
- Run `./cub3D <.cub file>`
- Press ESC or click cross on window's frame to exit the program.
- Game controlls:
  - Look left or right: ArrowLeft, ArrowRight
  - Move point of view: W, A, S, D
  - Rotate point of view with mouse

### Characteristics of .cub files (scene description files)
- Configuration of the used wall textures:
  - Four textures must be defined, specifiers are: **NO, EA, SO, WE**
  - Prototype: `<specifer> <path_to_texture>`
- Configuration of the floor and the celling color:
  - Two colors must be defined, specifiers are: **F** and **C**
  - Prototype: `<specifer> <R>, <G>, <B>`
  - R, G and B values ranging from 0 to 255.
- Configuration of the map:
  - Has to be the last element of the .cub file. No empty lines within the map content allowed.
  - Defines **walls (1)** and **empty spaces (0)** and **void ((space))**.
  - A valid map is always closed/surrounded by walls.
  - Defines spawn point and the spawn orientation of the player:
    - Facing north: **N**,
    - Facing east: **E**,
    - Facing south: **S**,
    - Facing west: **W**
 
 ### Example of a valid .cub file:
 
 <img width="236" alt="Screenshot 2022-12-17 at 10 30 41" src="https://user-images.githubusercontent.com/82594855/208235484-3d25ca5b-0b6f-4e59-a151-3bffd174508c.png"> [^1]

**Bonus:**
- Minimap
- Wall collision
- Usage of mouse to change rotate point of view

[^1]: take from the subject pdf
