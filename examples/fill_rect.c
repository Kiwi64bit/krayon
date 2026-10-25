#define KRAYON_IMPLEMENTATION
#include "krayon.h"
#include "utils/write_ppm.h"

#define WIDTH  800
#define HEIGHT 800

uint8_t data[WIDTH * HEIGHT * 4];
KrayonCanvas canvas = {
    .width = WIDTH,
    .height = HEIGHT,
    .data = data,
};

int main()
{
    krayon_fill_canvas(canvas, KRAYON_COLOR_WHITE);
    krayon_fill_rect(canvas, 0, 0, 600, 600, KRAYON_COLOR_RED);
    krayon_fill_rect(canvas, 200, 200, 600, 600, KRAYON_COLOR_YELLOW);
    krayon_fill_rect(canvas, 50, 100, 300, 200, KRAYON_COLOR_CYAN);
    krayon_fill_rect(canvas, 500, 450, 200, 300, KRAYON_COLOR_GREEN);
    write_ppm_file(
        canvas.data,
        canvas.width,
        canvas.height,
        "examples/images/fill_rect.ppm"
    );
    return 0;
}