#define KRAYON_IMPLEMENTATION
#include "krayon.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "dev_deps/stb_image_write.h"
#include <stdlib.h>
#include <time.h>

uint32_t random_color()
{
    uint32_t r = (uint32_t)(rand() % 256u);
    uint32_t g = (uint32_t)(rand() % 256u);
    uint32_t b = (uint32_t)(rand() % 256u);

    return KRAYON_COLOR_RGBA(r, g, b, 255u);
}

#define WIDTH  400
#define HEIGHT 400

uint8_t data[WIDTH * HEIGHT * 4];
KrayonCanvas canvas = {
    .width = WIDTH,
    .height = HEIGHT,
    .data = data,
};

int main()
{
    // srand(time(NULL));
    krayon_fill_canvas(canvas, KRAYON_COLOR_WHITE);
    int n = 50;
    int radius_min = 5;
    int radius_max = 40;
    for (int i = 0; i < n; i++) {
        int cx = rand() % canvas.width;
        int cy = rand() % canvas.height;
        int radius = (rand() % (radius_max - radius_min + 1)) + radius_min;
        uint32_t color = random_color();

        krayon_fill_circle(canvas, cx, cy, radius, color);
    }

    stbi_write_png(
        "examples/images/fill_circle.png",
        canvas.width,
        canvas.height,
        4,
        canvas.data,
        canvas.width * 4
    );
    return 0;
}