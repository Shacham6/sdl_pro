find_path(Catch2_INCLUDE_DIRS
    NAMES catch.hpp

    HINTS $ENV{CMAKE_LIBS}/*

    PATH_SUFFIXES include
)