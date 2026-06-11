#ifndef PUX_H
#define PUX_H

#ifdef _WIN32
  #ifdef PUX_EXPORT
    #define PUX_API __declspec(dllexport)
  #else
    #define PUX_API __declspec(dllimport)
  #endif
#else
  #define PUX_API __attribute__((visibility("default")))
#endif

extern "C" {

PUX_API void pg_init(int window_width, int window_height);

PUX_API void pg_clear(int r, int g, int b);

PUX_API void pg_present();

PUX_API void pg_draw_rect(int x, int y, int w, int h, int r, int g, int b);

PUX_API int pg_running();

PUX_API void pg_quit();

}

#endif // PUX_H
