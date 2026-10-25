/*
    Krayon - v0.1.0
    single-file graphics library that writes directly to memory.
    Inspired by https://github.com/tsoding/olive.c

LICENSE

  See end of file for license information.
*/

#ifndef INCLUDE_KRAYON_H
#define INCLUDE_KRAYON_H

#include <stdint.h>
#include <stdlib.h>

#define KRAYON_COLOR_WHITE   0xFFFFFFFF
#define KRAYON_COLOR_BLACK   0x000000FF
#define KRAYON_COLOR_RED     0xFF0000FF
#define KRAYON_COLOR_GREEN   0x00FF00FF
#define KRAYON_COLOR_BLUE    0x0000FFFF
#define KRAYON_COLOR_CYAN    0x00FFFFFF
#define KRAYON_COLOR_MAGENTA 0xFF00FFFF
#define KRAYON_COLOR_YELLOW  0xFFFF00FF

#define KRAYON_COLOR_RGBA(r, g, b, a)                                          \
    (((uint32_t)((r) & 0xFFu) << (8 * 3)) |                                    \
     ((uint32_t)((g) & 0xFFu) << (8 * 2)) |                                    \
     ((uint32_t)((b) & 0xFFu) << (8 * 1)) |                                    \
     ((uint32_t)((a) & 0xFFu) << (8 * 0)))

typedef uint32_t KrayonColor;

typedef struct KrayonCanvas {
    size_t width;
    size_t height;
    KrayonColor *pixels;
} KrayonCanvas;

void krayon_put_pixel(
    KrayonCanvas canvas,
    int x,
    int y,
    KrayonColor color
);

void krayon_fill_canvas(
    KrayonCanvas canvas,
    KrayonColor color
);

void krayon_fill_rect(
    KrayonCanvas canvas,
    int left,
    int top,
    int width,
    int height,
    KrayonColor color
);

void krayon_fill_circle(
    KrayonCanvas canvas,
    int cx,
    int cy,
    int radius,
    uint32_t color
);

#endif // INCLUDE_KRAYON_H

#ifdef KRAYON_IMPLEMENTATION
#undef KRAYON_IMPLEMENTATION

void krayon_put_pixel(KrayonCanvas canvas, int x, int y, KrayonColor color)
{
    if (!(0 <= y && y < (int)canvas.height)) return;
    if (!(0 <= x && x < (int)canvas.width)) return;
    canvas.pixels[y * canvas.width + x] = color;
}

void krayon_fill_canvas(KrayonCanvas canvas, KrayonColor color)
{
    for (size_t y = 0; y < canvas.height; y++) {
        for (size_t x = 0; x < canvas.width; x++) {
            krayon_put_pixel(canvas, x, y, color);
        }
    }
}

void krayon_fill_rect(
    KrayonCanvas canvas,
    int left,
    int top,
    int width,
    int height,
    KrayonColor color
)
{
    int right = left + width - 1;
    int bottom = top + height - 1;

    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            krayon_put_pixel(canvas, x, y, color);
        }
    }
}

void krayon_fill_circle(
    KrayonCanvas canvas,
    int cx,
    int cy,
    int radius,
    uint32_t color
)
{
    int left = cx - radius, right = cx + radius;
    int top = cy - radius, bottom = cy + radius;
    int radius_squared = radius * radius;
    int dx, dy;
    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            dx = x - cx;
            dy = y - cy;
            if (dx * dx + dy * dy > radius_squared) continue;
            krayon_put_pixel(canvas, x, y, color);
        }
    }
}

void krayon_fill_ellipse(
    KrayonCanvas canvas,
    int cx,
    int cy,
    int ra,
    int rb,
    KrayonColor color
)
{
    int left = cx - ra, right = cx + ra;
    int top = cy - rb, bottom = cy + rb;
    int ra_2 = ra * ra, rb_2 = rb * rb;
    int rab_2 = ra_2 * rb_2;
    int dx, dy;
    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            dx = x - cx;
            dy = y - cy;
            if (!(dx * dx * rb_2 + dy * dy * ra_2 <= rab_2)) continue;
            krayon_put_pixel(canvas, x, y, color);
        }
    }
}

void krayon_line(
    KrayonCanvas canvas,
    int x0,
    int y0,
    int x1,
    int y1,
    KrayonColor color
)
{
    // Bresenham's line algorithm
    int dx = abs(x1 - x0);
    int dy = -abs(y1 - y0);

    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;

    int err = dx + dy, e2;

    while (1) {
        krayon_put_pixel(canvas, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;

        e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y0 += sy;
        }
    }
}

#endif // KRAYON_IMPLEMENTATION

/*
------------------------------------------------------------------------------
MIT License

Copyright (c) 2026 Kiwi64bit

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
------------------------------------------------------------------------------
*/