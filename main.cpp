#include <SDL2/SDL.h>
#include <iostream>
#include <array>

const int ROWS = 250;
const int COLS = 250;

int checkNextStep(std::array<std::array<int, ROWS>, COLS> &grid, const int x, const int y)
{

    int neighbours = 0;

    // Count all the neighbouring cells
    for (int i = x - 1; i <= x + 1; i++)
    {
        if (i < 0 || i >= ROWS)
            continue;
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (j < 0 || j >= COLS)
                continue;
            if (i == x && j == y)
                continue;
            if (grid[i][j] == 1)
                neighbours++;
        }
    }

    // If there are fewer than two neighbours alive and the cell is 1, return 0
    if (neighbours < 2 && grid[x][y] == 1)
        return 0;
    // If there are more than three neighbours, return 0
    if (neighbours > 3)
        return 0;
    // If the cell is dead and there are exactly three neighbours, return 1
    if (neighbours == 3 && grid[x][y] == 0)
        return 1;
    // If there are two or three neighbours, return 1
    if ((neighbours == 2 || neighbours == 3) && grid[x][y] == 1)
        return 1;
    // Otherwise, return 0
    return 0;
}

int main(int argv, char **args)
{
    // Establish initial grid and buffer
    std::array<std::array<int, ROWS>, COLS> grid;
    std::array<std::array<int, ROWS>, COLS> buffer;

    // Establish SDL variables
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(ROWS * 2, COLS * 2, SDL_WINDOW_ALLOW_HIGHDPI, &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);

    // Set the grid to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // Initialize the grid with random values of 0 and 1, higher chance the value is 0
    for (auto &row : grid)
    {
        for (auto &cell : row)
        {
            if (rand() % 10 == 0)
                cell = 1;
            else
                cell = 0;
        }
    }

    // Main loop
    while (true)
    {
        // Loop through the grid and check the next step for each cell
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                buffer[i][j] = checkNextStep(grid, i, j);
            }
        }

        // Draw the grid
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (buffer[i][j] == 1)
                {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    SDL_RenderDrawPoint(renderer, i, j);
                }
            }
        }

        // Copy the buffer to the grid (move to next step)
        std::copy(buffer.begin(), buffer.end(), grid.begin());

        // Update the screen
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        // Check for quit event
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        {
            break;
        }
    }

    // SDL cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}