#pragma once
#include <example_2_application_context.hh>

namespace Example2 {
void GetAnImageOnScreen();
bool Init(ApplicationContext &context);
bool LoadMedia(ApplicationContext &context);
void Close(ApplicationContext &context);
} // namespace Example2