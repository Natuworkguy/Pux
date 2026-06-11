#include "pux.h"
#include <Python.h>
#include <cstdio>

void pg_clear(
    int r,
    int g,
    int b
)
{
    char buffer[512];

    snprintf(buffer, sizeof(buffer), R"(
screen.fill((%d, %d, %d))
)", r, g, b);
    PyRun_SimpleString(buffer);
}

void pg_present()
{
    PyRun_SimpleString(R"(
pygame.display.flip()
clock.tick(60)
)");
}

void pg_draw_rect(
    int x,
    int y,
    int w,
    int h,
    int r,
    int g,
    int b
)
{
    char buffer[512];

    snprintf(
        buffer,
        sizeof(buffer),
        R"(
pygame.draw.rect(
    screen,
    (%d, %d, %d),
    (%d, %d, %d, %d)
)
)",
        r,
        g,
        b,
        x,
        y,
        w,
        h
    );

    PyRun_SimpleString(buffer);
}
