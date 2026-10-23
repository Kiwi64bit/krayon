#define KRAYON_IMPLEMENTATION
#include "krayon.h"
#include "utils/write_ppm.h"
#include <stdlib.h>
#include <time.h>

uint32_t random_color()
{
    uint32_t r = (uint32_t)(rand() % 256u);
    uint32_t g = (uint32_t)(rand() % 256u);
    uint32_t b = (uint32_t)(rand() % 256u);

    return KRAYON_COLOR_RGBA(r, g, b, 255u);
}

#define WIDTH  800
#define HEIGHT 800

uint32_t pixels[WIDTH * HEIGHT];
KrayonCanvas canvas = {
    .width = WIDTH,
    .height = HEIGHT,
    .pixels = pixels,
};

int main()
{
    // srand(time(NULL));
    krayon_fill_canvas(canvas, KRAYON_COLOR_BLACK);

    int rows = 10, cols = 10;
    int cell_width = canvas.height / rows;
    int cell_height = canvas.width / cols;

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int cell_x = cell_height * x;
            int cell_y = cell_width * y;
            krayon_fill_ellipse(
                canvas,
                cell_x + cell_width / 2,
                cell_y + cell_height / 2,
                x * (cell_width / 2 - 10) / cols + 10,
                y * (cell_height / 2 - 10) / rows + 10,
                random_color()
            );
        }
    }
    write_ppm_file(
        canvas.pixels,
        canvas.width,
        canvas.height,
        "examples/images/fill_ellipse.ppm"
    );
    return 0;
}