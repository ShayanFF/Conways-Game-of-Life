# Conway's Game of Life, C++ Implementation

## Description

This is a C++ project that is my recreation of Conway's Game of Life. The initial state is randomly generated, and it uses the SDL library to visualize the simulation.

## Rules

Conway's Game of Life is played on a two-dimensional grid of cells, where each cell can either be alive or dead. The game evolves in discrete generations, with the following rules applied simultaneously to all cells:

1. Any live cell with fewer than two live neighbors dies, as if by underpopulation.
2. Any live cell with two or three live neighbors survives to the next generation.
3. Any live cell with more than three live neighbors dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

## Visualization

This project utilizes the SDL library to provide a graphical visualization of the Game of Life simulation. The SDL window displays the grid of cells, with live cells represented by white pixels and dead cells as black pixels. The simulation plays automatically, with each generation updating based on the rules mentioned above.

## Turing Completeness

It is worth noting that Conway's Game of Life, despite its simplicity, is Turing complete.

## Usage

To compile and run the project, make sure you have a C++ compiler and the SDL library installed. Clone the repository and compile main.cpp to run the program.

Alternatively, I have included the compiled executable which is included in the repository and under releases.
