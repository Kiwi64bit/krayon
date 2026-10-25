#define KRAYON_IMPLEMENTATION
#include "krayon.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "third_party/stb_image_write.h"

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
    krayon_fill_canvas(canvas, KRAYON_COLOR_WHITE);
    krayon_fill_rect(canvas, 0, 0, 300, 300, KRAYON_COLOR_RED);
    krayon_fill_rect(canvas, 100, 100, 300, 300, KRAYON_COLOR_YELLOW);
    krayon_fill_rect(canvas, 50, 50, 150, 100, KRAYON_COLOR_CYAN);
    krayon_fill_rect(canvas, 250, 200, 100, 150, KRAYON_COLOR_GREEN);
    stbi_write_png(
        "examples/images/fill_rect.png",
        canvas.width,
        canvas.height,
        4,
        canvas.data,
        canvas.width * 4
    );
    return 0;
}