#include <windows.h>
#include <Python.h>

extern "C" {

__declspec(dllexport)
void pg_init(
    int window_width,
    int window_height
)
{
    char buffer[512];

    Py_Initialize();

    PyRun_SimpleString("print('pygame bindings for Rux (Pux)')\n");
    sprintf_s(buffer, R"(
import pygame

pygame.init()

screen = pygame.display.set_mode((%d, %d))

clock = pygame.time.Clock()

running = True
)", window_width, window_height);
    PyRun_SimpleString(buffer);
}

__declspec(dllexport)
void pg_clear()
{
    PyRun_SimpleString(R"(
screen.fill((0, 0, 0))
)");
}

__declspec(dllexport)
void pg_present()
{
    PyRun_SimpleString(R"(
pygame.display.flip()
clock.tick(60)
)");
}

__declspec(dllexport)
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

    sprintf_s(
        buffer,
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

__declspec(dllexport)
int pg_running()
{
    PyRun_SimpleString(R"(
running = True

for event in pygame.event.get():
    if event.type == pygame.QUIT:
        running = False
)");

    PyObject* main =
        PyImport_AddModule("__main__");

    PyObject* dict =
        PyModule_GetDict(main);

    PyObject* value =
        PyDict_GetItemString(dict, "running");

    return PyObject_IsTrue(value);
}

__declspec(dllexport)
void pg_quit()
{
    PyRun_SimpleString(R"(
pygame.quit()
)");

    Py_Finalize();
}

}