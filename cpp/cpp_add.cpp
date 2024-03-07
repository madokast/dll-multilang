#include<iostream>

// g++ -o3 -shared -o .\cpp\cpp_add.dll  .\cpp\cpp_add.cpp
extern "C" __declspec(dllexport) int Add(int a, int b) {
    std::cout << "dll::cpp_add " << a << " + " << b << std::endl;
    return a + b;
}
