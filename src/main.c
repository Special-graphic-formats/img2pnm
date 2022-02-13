#include <stdio.h>
#include <errno.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char** argv) {
    (void)argc;

    assert(*argv != NULL);
    const char *program_name = *argv++;

    if (*argv == NULL)
    {
        fprintf(stderr, "Usage: %s <input image>\n", program_name);
        fprintf(stderr, "ERROR: no args provided\n");
        exit(1);
    }

    const char *input_file_path = *argv++;
    int width, height, comp;

    stbi_uc* data = stbi_load(input_file_path, &width, &height, &comp, 0);
    if(data == NULL) {
        fprintf(stderr, "ERROR: can't read %s: %s\n", input_file_path, strerror(errno));
        exit(0);
    }

//     N=#comp     components
//       1           grey
//       2           grey, alpha
//       3           red, green, blue
//       4           red, green, blue, alpha

    printf("comp: %u\n", comp);

    return 0;
}