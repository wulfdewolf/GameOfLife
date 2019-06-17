#ifndef HEADER_H
#define HEADER_H

// libraries to import
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL2/SDL.h>

// val macros
#define GENERATIONS 100

#define RECT_HEIGHT 5
#define RECT_WIDTH 5

// definition of cel struct
struct cel{int curr; char team; int next;};

// two possible initializers for the 2d array
void randomize(struct cel** grid, int rows, int cols);
void read_input(struct cel** grid, int rows, int cols, FILE *file);

// function that saves the grid's state
void write_output(struct cel** grid, int rows, int cols, char *fname);

// cel struct procedures
struct cel* make_cel(int , char, int);
void next_to_curr(struct cel**);
char celchar(struct cel c);
void print_cel(struct cel **c);

// logic procedures
void logic(struct cel** grid, int rows, int cols);
void calcn(int rowidx, int colidx, int *a, int *b, struct cel** grid, int rows, int cols);
void go_to_next_gen(struct cel** grid, int rows, int cols);

// gui procedures
void draw_window(struct cel** grid, int rows, int cols);
void initialize_window(const char* title, int rows, int cols);
void free_gui();

// grid procedures
void free_inside(struct cel** grid, int rows, int cols);
struct cel** create_grid(int r, int c);

// terminal mode of game
void print_to_terminal(struct cel** grid, int rows, int cols);

#endif
