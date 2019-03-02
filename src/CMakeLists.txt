find_package(SDL2)


set(SDL_PRO_LIB_SRC
    getting_an_image_on_the_screen
    example_3_events
)

add_library(sdl_pro_lib ${SDL_PRO_LIB_SRC}) 
target_include_directories(sdl_pro_lib PUBLIC "../include/" ${SDL2_INCLUDE_DIRS}) 
target_link_libraries(sdl_pro_lib PUBLIC ${SDL2_LIBRARIES})

add_executable(sdl_pro main) 
target_link_libraries(sdl_pro PUBLIC sdl_pro_lib)
