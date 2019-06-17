#include "header.h"


/*                                                                    *
*                                                                     *
*                             INPUT/OUTPUT                            *
*                                                                     *
*                                                                     */



// initialises given grid by reading a given txtfile
void read_input(struct cel** grid, int rows, int cols, FILE *file){
  fgetc(file);                                                                  // go to the next line because we just read the rows and cols values
  char c;
  for(int i = 0; i < rows; i++){                                                // loop over 2d array
    for(int j = 0; j < cols+2; j++){
      fscanf(file, "%c", &c);                                                   // get a char from file
      switch(c){                                                                // switch case on char
        case ' ': *(grid + i*cols+ j) = make_cel(0,0,0);break;
        case '\n': break;
        case 'I': break;                                                        // placerholder char to make the inputfile more clear
        case '#': *(grid + i*cols + j) = make_cel(1, '#', 1);break;
        case '0': *(grid + i*cols + j) = make_cel(1, '0', 1);break;
        case EOF: printf("ERROR INPUTFILE NOT COMPLETE\n");break;
        default: printf("ERROR WRONG CHAR IN INPUTFILE on %i, %i: %c\n", i, j, c);break;
      }
    }
  }
  fclose(file);
}


// writes state of given grid to a txtfile
void write_output(struct cel** grid, int rows, int cols, char *fname){
  FILE* file = fopen(fname, "w+");                                              // open file
  fprintf(file, "%i\n", rows);                                                  // save rows and cols
  fprintf(file, "%i\n", cols);
  for(int i = 0; i < rows+1; i++){
    for(int j = 0; j < cols; j++){
      if(i == rows){
   	   fprintf(file, "I");                                                      // put placeholder I at max right
      } else {
          fprintf(file, "%c", celchar(**(grid + i*cols + j)));
      };
    };
      fprintf(file, "I\n");                                                     // put placeholder I at max under
  };
  fclose(file);
}
