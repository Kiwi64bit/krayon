#ifndef WRITE_PPM_H_INCLUDED
#define WRITE_PPM_H_INCLUDED

#include <stdint.h>
#include <stdio.h>

#define _COLOR_R(c) ((uint8_t)((c) >> (8 * 3)))
#define _COLOR_G(c) ((uint8_t)((c) >> (8 * 2)))
#define _COLOR_B(c) ((uint8_t)((c) >> (8 * 1)))
#define _COLOR_A(c) ((uint8_t)((c) >> (8 * 0)))

int write_ppm_file(
    const uint8_t *data,
    size_t width,
    size_t height,
    const char *file_path
)
{
    FILE *outfile;

    outfile = fopen(file_path, "wb");
    if (!outfile) {
        perror("Unable to open file");
        return -1;
    }

    fprintf(outfile, "P6\n%zu %zu\n255\n", width, height);
    if (ferror(outfile)) {
        perror("Unable to write to file");
        fclose(outfile);
        return -1;
    }

    for (size_t i = 0; i < width * height; i++) {
        fwrite(&data[i * 4], 1, 3, outfile);
    }

    printf("File generated successfully: %s\n", file_path);
    return 0;
}

#endif // WRITE_PPM_H_INCLUDED