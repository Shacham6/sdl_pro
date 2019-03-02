#include <SDL.h>

#include <example_3_events.hh>
#include <print.hh>

namespace Example3 {

ApplicationContext::ApplicationContext() {
  Window = nullptr;
  ScreenSurface = nullptr;
  PressSomethingPlease = nullptr;
}

void LaunchExample3() {
  ApplicationContext context;

  if (!InitApplication(context)) {
    Print("Failed to init application.");
    return;
  }

  if (!LoadMedia(context)) {
    Print("Failed to load media.");
    return;
  }

  if (!ApplyMedia(context)) {
    Print("Failed to apply media.");
    return;
  }

  PollForEvents(context);

  Close(context);
}

bool InitApplication(ApplicationContext &context) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    Print("SDL failed to init video subsystem! SDL_Error: ", SDL_GetError());
    return false;
  }

  context.Window =
      SDL_CreateWindow("Hello Example 3!", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 1024, 640, SDL_WINDOW_SHOWN);

  if (!context.Window) {
    Print("Could not create window! SDL_Error: ", SDL_GetError());
    return false;
  }

  context.ScreenSurface = SDL_GetWindowSurface(context.Window);
  if (!context.ScreenSurface) {
    Print("Could not get screen surface for main window! SDL_Error: ",
          SDL_GetError());
    return false;
  }

  return true;
}

bool LoadMedia(ApplicationContext &context) {
  context.PressSomethingPlease =
      SDL_LoadBMP("resources/press_something_please.bmp");
  if (!context.PressSomethingPlease) {
    Print("Could not load resource! SDL_Error: ", SDL_GetError());
    return false;
  }

  return true;
}

bool ApplyMedia(ApplicationContext &context) {
  int blitResult = SDL_BlitSurface(context.PressSomethingPlease, NULL,
                                   context.ScreenSurface, NULL);
  if (blitResult < 0) {
    Print("Failed to blit to screen surface! SDL_Error: ", SDL_GetError());
    return false;
  }

  SDL_UpdateWindowSurface(context.Window);

  return true;
}

void Close(ApplicationContext &context) {
  SDL_FreeSurface(context.ScreenSurface);
  context.ScreenSurface = nullptr;

  SDL_DestroyWindow(context.Window);
  context.Window = nullptr;

  // Quit all SDL subsystems
  SDL_Quit();
}

void PollForEvents(ApplicationContext &context) {
  // Main loop flag
  bool quit = false;

  // Event handler
  SDL_Event e;

  // Processing the events
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
        Print("Quitting application..");
      }
    }
  }
}

} // namespace Example3