#ifndef PPMIO_H

#define PPMIO_H

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Pixel;

// PPM write and read
Pixel *ppm_read(int *rows, int *cols, int * colors, char *filename);
void ppm_write(Pixel *image, int rows, int cols, int colors, char *filename);

// PGM write and read
unsigned char *pgm_read(int *rows, int *cols, int *intensities, char *filename);
void pgm_write(unsigned char *image, long rows, long cols, int intensities, char *filename);
void pgm_writef(float *src, int rows, int cols, char *filename);

#endif
