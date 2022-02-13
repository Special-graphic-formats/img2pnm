#ifndef PPM_H_
#define PPM_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Export raw pixel data to a PPM file
 * 
 * @param file_path Output file path
 * @param data Raw pixel data
 * @param width Image width
 * @param height Image height
 * @param comp Image composition (G/GA/RGB/RGBA)
 */
void export_ppm(const char *file_path, const unsigned char *data, const int width, const int height, const int comp);

#endif // PPM_H_