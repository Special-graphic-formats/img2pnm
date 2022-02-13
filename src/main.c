#include <stdbool.h>

#include "ppm.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

/**
 * @brief Print the program usage and exit with code 1
 *
 * @param program_name The program name
 */
void print_usage_and_exit(const char *program_name)
{
    fprintf(stderr, "Usage: %s <input image> [-o output path]\n", program_name);
    exit(1);
}

int main(int argc, char **argv)
{
    assert(*argv != NULL);

    char *output_file_path = NULL;
    char *input_file_path = NULL;

    // parse command args
    for (int i = 1; i < argc; i++)
    {
        char *opt = argv[i];
        if (opt[0] == '-')
        {
            // ouput file path option
            if (strcmp(opt + 1, "o") == 0 || strcmp(opt + 1, "output") == 0)
            {
                // if output file path was already set
                if (output_file_path != NULL)
                {
                    fprintf(stderr, "ERROR: you can only provide one output file path\n");
                    print_usage_and_exit(argv[0]);
                }

                // check if a parameter was provided
                if (argv[i + 1] != NULL)
                {
                    output_file_path = argv[i + 1];
                    i++;
                }
                else
                {
                    fprintf(stderr, "ERROR: no path provided after `%s`\n", opt);
                    print_usage_and_exit(argv[0]);
                }
            }
            // unknown option
            else
            {
                fprintf(stderr, "ERROR: unrecognized option `%s`\n", opt);
                print_usage_and_exit(argv[0]);
            }
        }
        else
        {
            // if input file path was already set
            if (input_file_path != NULL)
            {
                fprintf(stderr, "ERROR: you can only provide one input file\n");
                print_usage_and_exit(argv[0]);
            }

            input_file_path = opt;
        }
    }

    // if no input file was provided
    if (input_file_path == NULL)
    {
        fprintf(stderr, "ERROR: no input file provided\n");
        print_usage_and_exit(argv[0]);
    }

    // auto set output file path if it the user didn't provide it
    bool need_free = false;
    if (output_file_path == NULL)
    {
        output_file_path = (char *)malloc(strlen(input_file_path) + 4);
        strcpy(output_file_path, input_file_path);
        strcat(output_file_path, ".ppm");

        need_free = true;
    }

    // load source image
    int width, height, comp;

    stbi_uc *data = stbi_load(input_file_path, &width, &height, &comp, 0);
    if (data == NULL)
    {
        fprintf(stderr, "ERROR: can't open %s for reading: %s\n", input_file_path, strerror(errno));
        exit(1);
    }

    // export as ppm and free data
    export_ppm(output_file_path, data, width, height, comp);
    stbi_image_free(data);

    if (need_free)
    {
        free(output_file_path);
    }

    printf("Ok\n");

    return 0;
}