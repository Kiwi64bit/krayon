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

void krayon_fill_canvas(
    KrayonCanvas canvas,
    KrayonColor color
);

#endif // INCLUDE_KRAYON_H

#ifdef KRAYON_IMPLEMENTATION
#undef KRAYON_IMPLEMENTATION

void krayon_fill_canvas(KrayonCanvas canvas, KrayonColor color)
{
    for (size_t y = 0; y < canvas.height; y++) {
        for (size_t x = 0; x < canvas.width; x++) {
            canvas.pixels[y * canvas.width + x] = color;
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