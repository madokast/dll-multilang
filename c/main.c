#include <stdio.h>
#include <windows.h>

typedef int (*c_add)(int, int); // Example signature, adjust as needed

void run(char* dll_path) {
    printf("LoadLibrary %s\n", dll_path);
    HINSTANCE hDll = LoadLibrary(dll_path);
    if (hDll == NULL) {
        printf("Failed to load DLL\n");
        return;
    }
    printf("GetProcAddress Add in %s\n", dll_path);
    c_add myFunction = (c_add) GetProcAddress(hDll, "Add");
    if (myFunction == NULL) {
        printf("Failed to get function address\n");
        FreeLibrary(hDll);
        return;
    }
    printf("Call Add in %s\n", dll_path);
    int result = myFunction(42, 33); // Example argument
    printf("Result: %d\n", result);

    FreeLibrary(hDll);
    printf("FreeLibrary %s\n", dll_path);
}
 
// gcc -o3 -o .\c\main.exe .\c\main.c
int main() {
    run("./c_add.dll");
    run("../cpp/cpp_add.dll");
}

