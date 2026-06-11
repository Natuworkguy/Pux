#include "pux.h"
#include <Python.h>
#include <cstdio>

void pg_init(
    int window_width,
    int window_height
)
{
    char buffer[512];

    Py_Initialize();

    PyRun_SimpleString("print('pygame bindings for Rux (Pux)')\n");
    snprintf(buffer, sizeof(buffer), R"(
import pygame

pygame.init()

screen = pygame.display.set_mode((%d, %d))

clock = pygame.time.Clock()

running = True
)", window_width, window_height);
    PyRun_SimpleString(buffer);
}

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

void pg_quit()
{
    PyRun_SimpleString(R"(
pygame.quit()
)");

    Py_Finalize();
}
