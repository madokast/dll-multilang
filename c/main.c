#include <stdio.h>
#include <windows.h>

typedef int (*c_add)(int, int); // Example signature, adjust as needed

// gcc -o3 -o .\c\main.exe .\c\main.c
int main() {
    printf("LoadLibrary ./c_add.dll\n");
    HINSTANCE hDll = LoadLibrary("./c_add.dll");
    if (hDll == NULL) {
        printf("Failed to load DLL\n");
        return 1;
    }
    printf("GetProcAddress Add in ./c_add.dll\n");
    c_add myFunction = (c_add) GetProcAddress(hDll, "Add");
    if (myFunction == NULL) {
        printf("Failed to get function address\n");
        FreeLibrary(hDll);
        return 1;
    }
    printf("Call Add in ./c_add.dll\n");
    int result = myFunction(42, 33); // Example argument
    printf("Result: %d\n", result);

    FreeLibrary(hDll);
    printf("FreeLibrary ./c_add.dll\n");
    return 0;
}

