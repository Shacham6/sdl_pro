#pragma once

#include <iostream>

template <typename T, typename... Args> void Print(T &t, Args... args) { 
    std::cout << t;
    Print(args...);
}

template <typename T> void Print(T &t) { 
    std::cout << t << std::endl;
}
