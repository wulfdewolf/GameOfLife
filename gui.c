#include "header.h"


/*                                                                    *
*                                                                     *
*                          GRAPHICAL INTERFACE                        *
*                                                                     *
*                                                                     */

// MOST OF CODE USED FROM ASSISTANT FILES

// declaration of renderer
static SDL_Renderer *renderer;
// declaration of window
static SDL_Window *window;

void set_color_black(){
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void set_color_red(){
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
}

void set_color_white(){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

// draws the window from a given grid
void draw_window(struct cel** grid, int rows, int cols){
  SDL_RenderClear(renderer);                                          // resets window and clears everything
  int idxcol = 0;                                                     // creates counters to keep track of cels
  int idxrow = 0;
  for(int i = 0; i < rows; i++){                                      // loop over grid
    for(int j = 0; j < cols; j++){
      switch((*(grid + i*cols + j))->curr){                           // switch case on cel
        case(1):                                                      // if it lives
          if((*(grid + i*cols + j))->team == '#'){
          set_color_black();                                          // set color to black if team is #
        } else set_color_red();                                       // set color to red if team is #
          break;
        case(0): set_color_white();break;                             // set color to white if it's dead
      }
      SDL_Rect rectangle = {idxcol, idxrow, RECT_WIDTH, RECT_HEIGHT}; // create rectangle for cel
      SDL_RenderFillRect(renderer, &rectangle);
      idxcol = idxcol + RECT_WIDTH;
    }
    idxcol = 0;
    idxrow = idxrow + RECT_HEIGHT;
  }
  SDL_RenderPresent(renderer);
}


// code imported from assistant files

void initialize_window(const char* title, int rows, int cols){
  /*
   * Code based on a.o. http://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php
   */
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }
  /*definition of window*/
  window = SDL_CreateWindow(title, 0, 0, cols * RECT_WIDTH, rows * RECT_WIDTH, SDL_WINDOW_SHOWN);
  /*control is window allocation worked*/
  if (window == NULL) {
    printf("Couldn't set screen mode to required dimensions: %s\n", SDL_GetError());
    exit(1);
  }
  /* Initialise the renderer. */
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  /*
   * Make white the default color of renderer.
   * This is the color of the background.
   */
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}


 /* Deallocates all SDL structures that were allocated dynamically.*/
void free_gui() {

	/* Deallocates the window. */
	SDL_DestroyWindow(window);
	/* Deallocates the renderer. */
	SDL_DestroyRenderer(renderer);

	/* Quit SDL. */
	SDL_Quit();
}
