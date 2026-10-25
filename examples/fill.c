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
    krayon_fill_canvas(canvas, 0x60C1C8FF);
    write_ppm_file(
        canvas.data,
        canvas.width,
        canvas.height,
        "examples/images/fill.ppm"
    );
    return 0;
}