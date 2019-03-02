find_package(Catch2)
find_package(FakeIt)


add_executable(tests
    tests_main
) 

target_include_directories(tests 
    PRIVATE
    .
    ../include
    ${Catch2_INCLUDE_DIRS}
    ${FakeIt_INCLUDE_DIRS}
) 

target_link_libraries(tests
    PRIVATE
    sdl_pro_lib
)