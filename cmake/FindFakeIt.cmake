find_path(FakeIt_INCLUDE_DIRS
    NAMES fakeit.hpp

    HINTS
    $ENV{CMAKE_LIBS}/*

    PATH_SUFFIXES include
) 