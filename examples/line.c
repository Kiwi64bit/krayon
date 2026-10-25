#define KRAYON_IMPLEMENTATION
#include "krayon.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "third_party/stb_image_write.h"
#include <math.h>
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
#define PI     3.141592654

uint8_t data[WIDTH * HEIGHT * 4];
KrayonCanvas canvas = {
    .width = WIDTH,
    .height = HEIGHT,
    .data = data,
};

int main()
{
    krayon_fill_canvas(canvas, KRAYON_COLOR_BLACK);
    int n = 20;
    int width_half = WIDTH / 2;
    int height_half = HEIGHT / 2;
    int length = (width_half + height_half) / 2;
    double angle;
    for (int i = 0; i < n; i++) {
        angle = i * 2 * PI / n;
        krayon_line(
            canvas,
            width_half,
            height_half,
            width_half + length * cos(angle),
            height_half + length * sin(angle),
            random_color()
        );
    }

    stbi_write_png(
        "examples/images/line.png",
        canvas.width,
        canvas.height,
        4,
        canvas.data,
        canvas.width * 4
    );
    return 0;
}