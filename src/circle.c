#include <stdio.h>
#include <bmpfile.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char **argv) {

  // Data structure for storing the bitmap file
  bmpfile_t *bmp;
  // Data type for defining pixel colors (BGRA)
  rgb_pixel_t pixel = {255, 0, 0, 0};

  if (argc < 3) {
    printf("Please specify filename and radius as arguments!");
    return EXIT_FAILURE;
  }

  /* Instantiate bitmap, passing three parameters:
  *   - width of the image (in pixels)
  *   - Height of the image (in pixels)
  *   - Depth of the image (1 for greyscale images, 4 for colored images)
  */
  int width = 100;
  int height = width;
  int depth = 4;
  bmp = bmp_create(width, height, depth);

  // Code for drawing a centered circle of given radius...
  int radius = atoi(argv[2]);
  for(int x = -radius; x <= radius; x++) {
    for(int y = -radius; y <= radius; y++) {
      // If distance is smaller, point is within the circle
      if(sqrt(x*x + y*y) < radius) {
          /*
          * Color the pixel at the specified (x,y) position
          * with the given pixel values
          */
          bmp_set_pixel(bmp, width/2 + x, height/2 + y, pixel);
      }
    }
  }

  // Save image as .bmp file
  bmp_save(bmp, argv[1]);
  // Free resources before termination
  bmp_destroy(bmp);

  return 0;
}
