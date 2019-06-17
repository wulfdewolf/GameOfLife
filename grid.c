#include "header.h"

/*                                                                    *
*                                                                     *
*                                GRID                                 *
*                                                                     *
*                                                                     */

// frees the inside of a given grid
void free_inside(struct cel** grid, int rows, int cols){
	for(int i = 0; i < rows; i++){												 	// loop over grid
		for(int j = 0; j < cols; j++){
			free(*(grid + i*cols + j));                     		// free every cel inside
		}
	}
};

// dynamically allocate enough space for a grid of given rows and cols and return it
struct cel** create_grid(int rows, int cols){
	struct cel** g = malloc(rows*cols*sizeof(struct cel*));
	if(g != NULL){
	return g;
 }
};
