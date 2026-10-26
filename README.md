# Krayon

Krayon is a single-file graphics library written in C that writes directly to memory.
inspired by [olive.c](https://github.com/tsoding/olive.c).

## Features

- Single-header implementation.
- Direct Memory manipulation.
- No external dependencies.

> [!NOTE]
> Currently the library support filling rectangles, circles, and ellipses, and drawing lines. more will be added in the future.

## Usage

Define KRAYON_IMPLEMENTATION in one C source file before including krayon.h to enable the implementation.

```C
#define KRAYON_IMPLEMENTATION
#include "krayon.h"
```

In other source files, include the header normally:

```C
#include "krayon.h"
```

## Example

```C
#define KRAYON_IMPLEMENTATION
#include "krayon.h"

#define WIDTH  800
#define HEIGHT 600
#define CHANNELS 4 // RGBA

// Initializing an array that big in `main` will produce stack overflow.
// You can use `malloc`, but nobody wants to deal with memory allocation.
unsigned char pixels_data = [WIDTH * HEIGHT * CHANNELS]

int main(void) {
    KrayonCanvas canvas = {
        .width = WIDTH,
        .height = HEIGHT,
        .data = pixels_data
    };

    krayon_fill_canvas(canvas, KRAYON_COLOR_BLACK);
    krayon_fill_rect(canvas, 100, 100, 200, 150, KRAYON_COLOR_RED);
    krayon_fill_circle(canvas, 400, 300, 50, KRAYON_COLOR_GREEN);
    krayon_line(canvas, 0, 0, 800, 600, KRAYON_COLOR_BLUE);

    return 0;
}
```

> [!TIP]
> See the examples folder for more examples.

## License

[MIT](https://choosealicense.com/licenses/mit/)
