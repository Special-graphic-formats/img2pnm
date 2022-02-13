#include "ppm.h"

enum COMP
{
    /**
     * @brief Grey
     *
     */
    COMP_G = 1,

    /**
     * @brief Grey, Alpha
     *
     */
    COMP_GA = 2,

    /**
     * @brief Red, Green, Blue
     *
     */
    COMP_RGB = 3,

    /**
     * @brief Red, Green, Blue, Alpha
     *
     */
    COMP_RGBA = 4,
};

void export_ppm(const char *file_path, const unsigned char *data, const int width, const int height, const int comp)
{
    // open file for writing
    FILE *ouput_file = fopen(file_path, "w");
    if (ouput_file == NULL)
    {
        fprintf(stderr, "ERROR: can't open %s for writing: %s\n", file_path, strerror(errno));
        exit(1);
    }

    // write header
    fprintf(ouput_file, "P3\n");
    fprintf(ouput_file, "%d %d\n255\n", width, height);

    // write body
    const size_t count = width * height * comp;
    for (size_t i = 0; i < count; i += comp)
    {
        // process either Grey or RGB, not alpha
        if (comp == COMP_G || comp == COMP_GA)
        {
            fprintf(ouput_file, "%d %d %d ", data[i], data[i], data[i]);
        }
        else if (comp == COMP_RGB || comp == COMP_RGBA)
        {
            fprintf(ouput_file, "%d %d %d ", data[i], data[i + 1], data[i + 2]);
        }
        else
        {
            assert(0 && "unreachable");
        }
    }

    fclose(ouput_file);
}