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
    krayon_fill_canvas(canvas, KRAYON_COLOR_WHITE);
    int n = 100;
    int radius_min = 10;
    int radius_max = 50;
    for (int i = 0; i < n; i++) {
        int cx = rand() % canvas.width;
        int cy = rand() % canvas.height;
        int radius = (rand() % (radius_max - radius_min + 1)) + radius_min;
        uint32_t color = random_color();

        krayon_fill_circle(canvas, cx, cy, radius, color);
    }

    write_ppm_file(
        canvas.pixels,
        canvas.width,
        canvas.height,
        "examples/images/fill_circle.ppm"
    );
    return 0;
}