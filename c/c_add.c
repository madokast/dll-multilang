#include<stdio.h>

// gcc -o3 -shared -o .\c\c_add.dll  .\c\c_add.c
// strip .\c\c_add.dll
// upx .\c\c_add.dll
__declspec(dllexport) int Add(int a, int b) {
    printf("dll::c_add %d + %d\n", a, b);
    return a + b;
}
