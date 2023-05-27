// main.cpp

#include <iostream>
#include "mylib.h"
#include <dlfcn.h>

int main() {
    void* handle = dlopen("./libmylib.so", RTLD_LAZY);
    if (handle == nullptr) {
        std::cout << "Failed to load the library." << std::endl;
        return 1;
    }

    // Load the function symbol from the library
    typedef int (*AddFunction)(int, int);
    AddFunction add = reinterpret_cast<AddFunction>(dlsym(handle, "add"));

    if (add == nullptr) {
        std::cout << "Failed to load the symbol." << std::endl;
        dlclose(handle);
        return 1;
    }

    // Use the function from the library
    int result = add(2, 3);
    std::cout << "Result: " << result << std::endl;

    // Close the library
    dlclose(handle);

    return 0;
}
