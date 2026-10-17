#define KRAYON_IMPLEMENTATION
#include "krayon.h"
#include "utils/write_ppm.h"

#define WIDTH  800
#define HEIGHT 800

KrayonColor pixels[WIDTH * HEIGHT];
KrayonCanvas canvas = {
    .width = WIDTH,
    .height = HEIGHT,
    .pixels = pixels,
};

int main()
{
    krayon_fill_canvas(canvas, 0x60C1C8FF);
    write_ppm_file(
        canvas.pixels,
        canvas.width,
        canvas.height,
        "examples/images/fill.ppm"
    );
    return 0;
}