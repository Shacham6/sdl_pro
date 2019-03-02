// SDL includes
#include <SDL.h>

// Project includes
#include <getting_an_image_on_the_screen.hh>
#include <print.hh>

namespace Example2 {

bool ApplyMedia(ApplicationContext &context);

void GetAnImageOnScreen() {
  ApplicationContext context;

  if (!Init(context)) {
    Print("Could not initiate project! Exiting...");
    return;
  }

  if (!LoadMedia(context)) {
    Print("Could not load media! Exiting...");
    return;
  }

  if (!ApplyMedia(context)) {
    Print("Could not apply media!: Exiting...");
    return;
  }

  SDL_Delay(2000);

  Close(context);
}

bool Init(ApplicationContext &context) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    Print("SDL could not initialize! SDL_Error: ", SDL_GetError());
    return false;
  }

  SDL_Rect displayBound;
  SDL_GetDisplayBounds(0, &displayBound);

  context.Window =
      SDL_CreateWindow("Hello SDL!", displayBound.x + 30, displayBound.y + 30,
                       int(double(displayBound.w) / 1.4),
                       int(double(displayBound.h) / 1.4), SDL_WINDOW_SHOWN);

  if (!context.Window) {
    Print("Window could not be created! SDL_Error: ", SDL_GetError());
    return false;
  }

  context.ScreenSurface = SDL_GetWindowSurface(context.Window);

  return true;
}

bool LoadMedia(ApplicationContext &context) {
  auto const imagePath = "resources/hello_world.bmp";
  context.HelloWorld = SDL_LoadBMP(imagePath);
  if (!context.HelloWorld) {
    Print("Unable to load image: ", imagePath, "! SDL_Error: ", SDL_GetError());
    return false;
  }

  return true;
}

void Close(ApplicationContext &context) {
  // Deallocate surface
  SDL_FreeSurface(context.ScreenSurface);
  context.ScreenSurface = nullptr;

  // Destry window
  SDL_DestroyWindow(context.Window);
  context.Window = nullptr;

  // Quit SDL subsystems
  SDL_Quit();
}

bool ApplyMedia(ApplicationContext &context) {
  if (SDL_BlitSurface(context.HelloWorld, nullptr, context.ScreenSurface,
                      NULL) < 0) {
    Print("Could not Blit image to surface! SDL_Error: ", SDL_GetError());
    return false;
  }
  SDL_UpdateWindowSurface(context.Window);
  return true;
}

}