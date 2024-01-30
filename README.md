# cub3D

This project is inspired by the game Wolfenstein 3D. The goal of the project is to create a simple graphic engine capable of rendering a 3D maze using the Raycasting technique.

This project was developed in colaboration with FMihguel95 --> [fernacar](https://github.com/FMiguel95).

Files to support parser

https://docs.google.com/spreadsheets/d/1qg7l79Bjfqt4-D8Ztr7GokgM5wAl61f4juJhe6RCElw/edit#gid=0

movie 1

![video2](https://github.com/krammersf/4cub3D_fred/assets/127677607/7e644a9a-efb2-4133-838c-fedf11aa31f1)

movie 2

![video10](https://github.com/krammersf/4cub3D_fred/assets/127677607/66ce046c-dc95-405f-a8cd-59ca64e4addd)

movie 3

![video8](https://github.com/krammersf/4cub3D_fred/assets/127677607/dc6c8cd3-d467-4985-aaa1-b0a1f879dc98)


## Features

- 3D maze rendering using Raycasting.
- Wall textures support.
- Player movement with WASD keys.
- Player vision rotation with arrow keys.
- Map defined in a .cub file.

## Prerequisites

Before compiling and running the project, make sure you have the MiniLibX installed in project folder. For that, just do `make download` and you are ready to go!

## Compilation

To compile the project, run:
```shell
make
```
```shell
make bonus
```
This will compile the source files and generate the `cub3D` or `cub3D_bonus` executable.

## Execution
After compilation, you can run the game using the following command:

```shell
./cub3D <map>
```
```shell
./cub3D_bonus <map>
```

Replace `<map>` with the path to the map file you want to use. The map file should have the `.cub` extension and follow the format specified in the project.
Inside the `maps` folder there are folders with some examples of valid and invalid maps.

## Map

The maze map is defined in a .cub file. Example:

```plaintext
NO path_to_north_texture
SO path_to_south_texture
WE path_to_west_texture
EA path_to_east_texture

F 220,100,0
C 15,15,15

111111
100001
101101
10N001
111111
```

- `NO`, `SO`, `WE`, `EA`: Paths to wall textures.
- `F`: Floor color in RGB format.
- `C`: Ceiling color in RGB format.
- The map is represented using the letters `0` (empty space) and `1` (wall), and the spawn point with the orientation `N`, `S`, `E` or `W`. The map must be surrounded by walls.

## Controls MANDATORY

- W: Move forward.
- S: Move backward.
- A: Move left.
- D: Move right.
- Arrow keys: Rotate player's vision.
- ESC: Exit game.

## Controls BONUS

- W: Move forward.
- S: Move backward.
- A: Move left.
- D: Move right.
- Arrow keys: Rotate player's vision.
- ESC: Exit game.
- L: Change Wall.
- SPACE: Open and close doors.
- E: Shoot pistol.
- K: Make random color efect and change wall color. 
- MOUSE: One click in the window to control rotation with mouse, ESC to relese the control.

## Grade: 125/100

