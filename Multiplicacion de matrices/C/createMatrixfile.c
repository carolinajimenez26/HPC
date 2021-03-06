#include <stdio.h>
#include <stdlib.h>

typedef char* string;

void fillMatrix(float *M, int row, int col) { // fill a matrix with random numbers
  float a = 5.0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      M[i * col + j] = (float)rand() / (float)(RAND_MAX / a);
    }
  }
}

void print(float *M, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%.2f ", M[i * col + j]);
    }
    printf("\n");
  }
  printf("\n");
}

void writeMatrix(float *M, int row, int col, string file_name) {
  FILE *f = fopen(file_name, "w");
  fprintf(f, "%d\n%d\n", row, col);
  if (f == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      if (j + 1 == col) {
        fprintf(f, "%.2f", M[i * col + j]);
      } else {
        fprintf(f, "%.2f,", M[i * col + j]);
      }
    }
    fprintf(f, "%s\n", "");
  }

  fclose(f);
}

int main(int argc, char** argv) {
  if (argc =! 2) {
    printf("Must be called with the name of the out file\n");
    return 1;
  }
  int row, col;
  string file_name = argv[1];
  printf("File name: %s\n", file_name);
  scanf("%d %d", &row, &col);
  float *M = (float*)malloc(row*col*sizeof(float));
  fillMatrix(M, row, col);
  // print(M, row, col);
  writeMatrix(M, row, col, file_name);
  return 0;
}
