#include "header.h"

void print_file_header(BITMAPFILEHEADER_t* file_header) {
  printf("bfType     %d\n",   file_header->bfType);
  printf("bfSize     %u\n",   file_header->bfSize);
  printf("bfOffBits  %u\n\n", file_header->bfOffBits);
}

void print_info_header(BITMAPINFOHEADER_t* info_header) {
  printf("biSize          %u\n", info_header->biSize);
  printf("biWidth         %d\n", info_header->biWidth);
  printf("biHeight        %d\n", info_header->biHeight);
  printf("biPlanes        %u\n", info_header->biPlanes);
  printf("biBitCount      %u\n", info_header->biBitCount);
  printf("biCompression   %u\n", info_header->biCompression);
  printf("biSizeImage     %u\n", info_header->biSizeImage);
  printf("biXPelsPerMeter %d\n", info_header->biXPelsPerMeter);
  printf("biYPelsPerMeter %d\n", info_header->biYPelsPerMeter);
  printf("biClrUsed       %u\n", info_header->biClrUsed);
  printf("biClrImportant  %u\n", info_header->biClrImportant);
}

void print_pixel(PIXEL_t* pixel) {
  printf("%X %X %X\n", pixel->red, pixel->green, pixel->blue);
}

void save_image(BITMAPFILEHEADER_t* file_header, BITMAPINFOHEADER_t* info_header, PIXEL_t* bitmap_image, const char* filename) {
  FILE_t* fd = fopen(filename, "wb");

  if (fd == NULL) {
    printf("Couldn't save file.");
    return ;
  }
  
  fwrite(file_header, sizeof(BITMAPFILEHEADER_t), 1, fd);
  fwrite(info_header, sizeof(BITMAPINFOHEADER_t), 1, fd);
  fwrite(bitmap_image, sizeof(PIXEL_t), info_header->biHeight * info_header->biWidth, fd);
  fclose(fd);
}

void save_image(BITMAPFILEHEADER_t* file_header, BITMAPINFOHEADER_t* info_header, PIXEL_t* bitmap_image, const char* filename);
void one_color_image(BITMAPFILEHEADER_t* file_header, BITMAPINFOHEADER_t* info_header, PIXEL_t color, const char* filename) {
  unsigned int pixels_count = info_header->biHeight * info_header->biWidth;
  PIXEL_t*     pixels = malloc(sizeof(PIXEL_t) * pixels_count);

  for (unsigned int i = 0; i < pixels_count; i++)
    pixels[i] = color;

  save_image(file_header, info_header, pixels, filename);
}

void split_image(BITMAPFILEHEADER_t* file_header, BITMAPINFOHEADER_t* info_header, PIXEL_t* bitmap_image, unsigned int ratio, const char* filename) {
  BITMAPFILEHEADER_t* fcopy_header; 
  BITMAPINFOHEADER_t* icopy_header;
  PIXEL_t* pixels;
  unsigned int index = 0;

  if (info_header->biWidth % ratio != 0) {
    printf("Error: ratio must divide the width of the image.");
    return ;
  }

  fcopy_header = malloc(sizeof(BITMAPFILEHEADER_t));
  icopy_header = malloc(sizeof(BITMAPINFOHEADER_t));

  fcopy_header->bfType = 0x4D42;
  fcopy_header->bfOffBits = fcopy_header->bfSize = sizeof(BITMAPFILEHEADER_t) + sizeof(BITMAPINFOHEADER_t);;

  icopy_header->biSize = sizeof(BITMAPINFOHEADER_t);
  icopy_header->biWidth = info_header->biWidth / ratio;
  icopy_header->biHeight = info_header->biHeight;
  icopy_header->biPlanes = info_header->biPlanes;
  icopy_header->biBitCount = info_header->biBitCount;
  icopy_header->biSizeImage = icopy_header->biHeight * icopy_header->biWidth * 3;

  fcopy_header->bfSize += icopy_header->biSizeImage;
  pixels = malloc(sizeof(PIXEL_t) * icopy_header->biHeight * icopy_header->biWidth);

  for (unsigned int row = 0; row < info_header->biHeight; row++) {
    for (unsigned int col = 0; col < icopy_header->biWidth; col++) {
      pixels[index++] = bitmap_image[row * info_header->biWidth + col];
    }
  }

  save_image(fcopy_header, icopy_header, pixels, filename);
  free(fcopy_header);
  free(icopy_header);
  free(pixels);
}

void add_cross_image(BITMAPFILEHEADER_t* file_header, BITMAPINFOHEADER_t* info_header, PIXEL_t* bitmap_image, PIXEL_t color, const char* filename) {
  unsigned int pixels_count = info_header->biHeight * info_header->biWidth;
  PIXEL_t* pixels = malloc(sizeof(PIXEL_t) * pixels_count);

  unsigned int mid_row, mid_col, current;
  unsigned int row_padding, col_padding; // if even rows/cols make cross size 2

  row_padding = info_header->biWidth  % 2 == 0 ? 1 : 0;
  col_padding = info_header->biHeight % 2 == 0 ? 1 : 0;
  for (unsigned i = 0; i < pixels_count; i++)
    pixels[i] = bitmap_image[i];

  mid_row = info_header->biWidth  / 2;
  mid_col = info_header->biHeight / 2;
  for (unsigned int row = 0; row < info_header->biHeight; row++) {
    current = row * info_header->biWidth + mid_row;
    pixels[current] = pixels[current + row_padding] = color;
  }
  for (unsigned int col = 0; col < info_header->biWidth; col++) {
    current = mid_col * info_header->biWidth + col;
    pixels[current] = pixels[(mid_col + col_padding) * info_header->biWidth + col] = color;
  }

  save_image(file_header, info_header, pixels, filename);
}

int main(void) {
  BITMAPFILEHEADER_t* file_header;
  BITMAPINFOHEADER_t* info_header;
  FILE_t*  file; 
  PIXEL_t* bitmap_image;
  unsigned int pixels_count;

  file_header = malloc(sizeof(BITMAPFILEHEADER_t));
  info_header = malloc(sizeof(BITMAPINFOHEADER_t));

  if ((file = fopen("images/red.bmp", "rb")) == NULL) {
    printf("Error while openning bitmap file\n");
    return -1;
  }

  fread(file_header, sizeof(BITMAPFILEHEADER_t), 1, file);
  if (file_header->bfType != 0x4D42) {
    printf("File is not a bitmap");
    return -1;
  }

  pixels_count = info_header->biSizeImage;
  fread(info_header, sizeof(BITMAPINFOHEADER_t), 1, file);
  fseek(file, file_header->bfOffBits, SEEK_SET);

  print_file_header(file_header);
  print_info_header(info_header);

  if (pixels_count == 0)
    pixels_count = file_header->bfSize - file_header->bfOffBits;
  pixels_count /= 3;
  bitmap_image = malloc(sizeof(PIXEL_t) * pixels_count);

  fread(bitmap_image, sizeof(PIXEL_t), pixels_count, file);
  
  save_image(file_header, info_header, bitmap_image, "images/redcopy.bmp");
  one_color_image(file_header, info_header, (PIXEL_t){255, 255, 255}, "images/white.bmp");
  one_color_image(file_header, info_header, (PIXEL_t){255, 0, 0}, "images/blue.bmp");
  split_image(file_header, info_header, bitmap_image, 2, "images/ratio2.bmp");
  split_image(file_header, info_header, bitmap_image, 4, "images/ratio4.bmp");
  split_image(file_header, info_header, bitmap_image, 8, "images/ratio8.bmp");
  add_cross_image(file_header, info_header, bitmap_image, (PIXEL_t){0, 0, 0}, "images/crossblack.bmp");
  add_cross_image(file_header, info_header, bitmap_image, (PIXEL_t){255, 0, 0}, "images/crossblue.bmp");

  fclose(file);
  return 0;
}