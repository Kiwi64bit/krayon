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
    stbi_write_png(
        "examples/images/fill_ellipse.png",
        canvas.width,
        canvas.height,
        4,
        canvas.data,
        canvas.width * 4
    );
    return 0;
}