# Pux

Lightweight Pygame bindings for Rux through a native DLL bridge.

Pux exposes simple graphics, rendering, and window management functions from Pygame to Rux, making it possible to prototype games and graphical applications directly in Rux.

> Experimental project. Mostly built for fun, learning, and engine experimentation.

The actual Rux module is located [here](https://github.com/Natuworkguy/Pux-module).

---

# Features

- Window creation
- Rectangle rendering
- Screen clearing
- Display updates
- Event polling
- Simple game loop support
- Native DLL imports through Rux

---

# Example

[This section has moved](https://github.com/Natuworkguy/Pux-module/tree/main#example)


# How It Works

```text
Rux
 ↓
Pux bindings
 ↓
Native DLL bridge
 ↓
Python + Pygame
```

This repository is only the bindings layer.

The rendering and windowing functionality are powered internally by Python and Pygame through an embedded interpreter.

---

# Building

## Requirements

- Python 3.13
- CMake
- Visual Studio Build Tools / MSVC
- Pygame/Pygame-ce

Install dependencies:

```bash
pip install pygame
```

---

# Build Instructions

```powershell
.\build.ps1
```

The compiled DLL will be generated in:

```text
build/output/
```

---

# Project Structure

```text
Pux/
│
├── wrapper.cpp
├── CMakeLists.txt
├── Pux.rux
└── build/
```

---

# Current API

```rux
pg_init()
pg_clear()
pg_present()
pg_draw_rect(x, y, w, h)
pg_running() -> int
pg_set_title(title)
pg_quit()
```

---

# Notes

- This project is experimental.
- Pux currently targets Windows.
- Python and Pygame are still required internally.
- APIs may change frequently.

---

# License

MIT
