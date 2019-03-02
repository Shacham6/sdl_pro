#pragma once
#include <SDL_video.h>

namespace Example3 {

/**
 * The ApplicationContext, needed
 * for nearly all the operations
 * of the application.
 */
struct ApplicationContext {
  SDL_Window *Window;
  SDL_Surface *ScreenSurface;
  SDL_Surface *PressSomethingPlease;

  ApplicationContext();
};

/**
 * The third example is for handling SDL
 * events.
 * Events can be pretty much anything,
 * but the most intuitive example is
 * input handling.
 */
void LaunchExample3();

/**
 * Start the application
 * and fill all the properties
 * of the application context.
 */
bool InitApplication(ApplicationContext &context);

bool LoadMedia(ApplicationContext &context);

bool ApplyMedia(ApplicationContext &context);

void Close(ApplicationContext &context);

void PollForEvents(ApplicationContext &context);

}