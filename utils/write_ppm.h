#ifndef WRITE_PPM_H_INCLUDED
#define WRITE_PPM_H_INCLUDED

#include <errno.h>
#include <stdint.h>
#include <stdio.h>

#define _COLOR_R(c) ((uint8_t)((c) >> (8 * 3)))
#define _COLOR_G(c) ((uint8_t)((c) >> (8 * 2)))
#define _COLOR_B(c) ((uint8_t)((c) >> (8 * 1)))
#define _COLOR_A(c) ((uint8_t)((c) >> (8 * 0)))

int write_ppm_file(
    const uint32_t *pixels, size_t width, size_t height, const char *file_path
)
{
    int result = 0;
    FILE *outfile = NULL;

    outfile = fopen(file_path, "wb");
    if (!outfile) perror("Unable to open file");

    fprintf(outfile, "P6\n%zu %zu\n255\n", width, height);
    if (ferror(outfile)) {
        fclose(outfile);
        perror("Unable to write to file");
    }

    for (size_t i = 0; i < width * height; i++) {
        uint32_t pixel = pixels[i];
        uint8_t bytes[3] = {_COLOR_R(pixel), _COLOR_G(pixel), _COLOR_B(pixel)};
        fwrite(bytes, sizeof(bytes), 1, outfile);
        if (ferror(outfile)) perror("Failed to write to file");
    }

    printf("File generated successfully: %s\n", file_path);
    return result;
}

#endif // WRITE_PPM_H_INCLUDED