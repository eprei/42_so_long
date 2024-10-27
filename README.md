# So Long

A 2D game project developed as part of the 42 School curriculum. The game involves a character collecting items and finding the exit while navigating through a map defined in a `.ber` file.

## About

So Long is a simple 2D game where players must:
- Collect all items on the map
- Find and reach the exit
- Use the shortest possible path
- Navigate using W, A, S, D keys for movement

The project is built using:
- MinilibX: 42 School's graphics library for basic window management and pixel manipulation
- Libft: A custom C library developed as part of the 42 curriculum

## Learning Objectives

This project introduces students to:
- Basic graphics programming concepts
- Window management
- Event handling
- Sprite and texture manipulation
- Game state management
- Basic gameplay mechanics
- Map parsing and validation

## Technical Details

### Map Format
Maps must be stored in files with `.ber` extension and follow these rules:
- Must be rectangular
- Must be surrounded by walls ('1')
- Must contain:
  - One starting position ('P')
  - At least one collectible ('C')
  - One exit ('E')
  - Walls ('1')
  - Empty spaces ('0')
- Must have a valid path to collect all items and reach the exit

Example of a valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Controls
- `W`: Move up
- `A`: Move left
- `S`: Move down
- `D`: Move right
- `ESC`: Exit game
- Window's X button: Exit game

### Features
- Movement counter displayed in terminal
- Smooth window management
- Error handling for invalid maps
- Memory leak prevention
- Proper window event handling

## Project Structure

```
.
├── Makefile
├── game_init.c
├── map_process1.c
├── map_process2.c
├── maps/
│   ├── map1.ber
│   ├── map2.ber
│   ├── map3.ber
│   └── map4.ber
├── movement_process1.c
├── movement_process2.c
├── so_long.c
├── so_long.h
└── xpm/
    ├── 0.xpm
    ├── 1.xpm
    ├── C.xpm
    ├── E.xpm
    └── P.xpm
```

## Installation

1. Clone the repository
2. Run `make` to compile the project
3. Execute with a valid map: `./so_long maps/map1.ber`

## Code Standards

This project adheres to 42 School's strict coding standards (Norm), which enforces specific formatting and structural rules. While modern IDEs might suggest various optimizations, the code must comply with these educational constraints to maintain consistency and encourage fundamental understanding of C programming concepts.

## Error Management

The program exits gracefully with "Error\n" followed by a specific error message if:
- Map is not rectangular
- Map is not surrounded by walls
- Map has invalid number of exits, collectibles, or starting positions
- Map has invalid characters
- Map file is invalid or missing
- No valid path exists to complete the game

## Dependencies

- MinilibX library
- Math library (`-lm`)
- X11 include files (Linux)
- XShm include files (Linux)

## Compilation

The project includes a Makefile with the following rules:
- `make`: Compile the executable
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Recompile the project
