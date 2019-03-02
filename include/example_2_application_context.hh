#pragma once
#include <SDL_video.h>
namespace Example2 {

struct ApplicationContext {
  SDL_Window *Window;
  SDL_Surface *ScreenSurface;
  SDL_Surface *HelloWorld;

  ApplicationContext();
};

} // namespace Example2