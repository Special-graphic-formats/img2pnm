#ifndef PPM_H_
#define PPM_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

void export_ppm(const char *file_path, const unsigned char *data, const int width, const int height, const int channels);

#endif // PPM_H_