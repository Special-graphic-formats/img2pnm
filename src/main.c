#include "ppm.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char **argv)
{
    (void)argc;

    assert(*argv != NULL);
    const char *program_name = *argv++;

    // check if any arg was provided
    if (*argv == NULL)
    {
        fprintf(stderr, "Usage: %s <input image>\n", program_name);
        fprintf(stderr, "ERROR: no args provided\n");
        exit(1);
    }

    // load source image
    const char *input_file_path = *argv++;
    int width, height, comp;

    stbi_uc *data = stbi_load(input_file_path, &width, &height, &comp, 3);
    if (data == NULL)
    {
        fprintf(stderr, "ERROR: can't open %s for reading: %s\n", input_file_path, strerror(errno));
        exit(1);
    }

    // export as ppm and free data
    export_ppm("output.ppm", data, width, height, comp);
    stbi_image_free(data);

    return 0;
}