#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

  typedef unsigned char  BYTE;
  typedef unsigned short WORD;
  typedef unsigned int   DWORD;
  typedef int            LONG;

# pragma pack(2)
  typedef struct tagBITMAPFILEHEADER {
    WORD  bfType;
    DWORD bfSize;
    WORD  bfReserved1;
    WORD  bfReserved2;
    DWORD bfOffBits;
  } BITMAPFILEHEADER_t;

// pragma pack sets the alignment in the structure
# pragma pack(2)
  typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
  } BITMAPINFOHEADER_t;

# pragma pack(1)
  typedef struct tagRGBQUAD {
    BYTE blue;
    BYTE green;
    BYTE red;
  } PIXEL_t;

  typedef FILE FILE_t;
#endif