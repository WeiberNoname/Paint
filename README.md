# Paint

> ## C_PLUS_Version

|Qt Application design|
| --- | 
|  Qt, It is an open source cross-platform application designed for software development; its main purpose is to involve "Graphical User Interfaces` applications that display the GUIs from software design. It has been classified as a widget toolkit and also supports non-GUI programs like command-line tools. This development maintains various compilers, including GCC`,  `VScode`, etc. (Cross platform: `Linux, Windows, macOS`) |
##### Available in (X11): 5/xx/2023 `sudo apt-get install build-essential libgl1-mesa-dev`
##### Check if QTDIR environment variable has been set: `echo $QTDIR`
##### Export the path that include the Qt(Software): `export QTDIR=/usr/lib/qt5`
##### Exception : Additional step :`export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/qt5/lib`

* ### X11 server display
##### Find out required libraries: `pkg-config --libs opencv x11`
##### Compile the file: `g++ example1.cpp -lX11 -o example1`,`g++ Paint.cpp -o Paint -lX11 -lopencv_core -lopencv_highgui -lopencv_imgcodecs`
##### Run the program:  `./example1` 

> ## C++ static library for C++:
* #### First create a file called "library.cpp".
```
//The library called library.h
#include "library.h"
int add(int a, int b) {
    return a + b;
}
```
* #### Second create a library header file called "library.h".
```
#ifndef LIBRARY_H
#define LIBRARY_H
int add(int a, int b);
#endif
```
* #### Third compile the source file into an object file.
```
g++ -c library.cpp -o library.o
```

* #### Fourth create a static library called "liblibrary.a".
```
ar rcs liblibrary.a library.o
```

* #### Fifth create an example program to run the library.(`#include "library.h"`)
```
// example.cpp
#include <iostream>
#include "library.h"
int main() {
    int result = add(2, 3);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```

* #### Sixth compile the program and against the static library.
```
g++ example.cpp -L. -llibrary -o example
```

#### Result:
```
Result: 5
```


> ## C++ dynamic library for C++:
* #### First create a file called "library.cpp".
```
```
![Screenshot 2023-05-27 192520](https://github.com/WeiberNoname/Paint/assets/129390032/3a0899b3-394a-47a3-a677-f1b0f618c78a)



> ## C++ dynamic library for C++:
* #### First create a file called "mylib.cpp".
```
#include "mylib.h"
int add(int a, int b) {
    return a + b;
}
```
* #### Second create a library header file called "mylib.h".
```
#ifndef MYLIB_H
#define MYLIB_H
#ifdef __cplusplus
extern "C" {
#endif
int add(int a, int b);
#ifdef __cplusplus
}
#endif
#endif
```
* #### Third compile the source file into a dynamic shared library file.
    #### `-fPIC` Generate position-independent code.
* ##### Position-Independent Code: Dynamic executable is the inverse of position-independent and is bound to an address in memory, whereas position-independent code is not tied to a fixed address in memory. This technique accepts program processes in different memory efficiently and proposes to be the best practice with shared libraries. 
```
g++ -shared -fPIC mylib.cpp -o libmylib.so
```
* #### Fourth create a `main.cpp`.
```
#include <iostream>
#include "mylib.h"
#include <dlfcn.h>
```


* #### Fifth compile the program.
```
g++ main.cpp -ldl -o myprogram
```

* #### Sixth run the program.
```
./myprogram
```


### References:
[Official Qt(software)](https://wiki.qt.io/Install_Qt_5_on_Ubuntu)

[Qt for Linux/X11](https://doc.qt.io/qt-6/linux.html)

[Qt (software)Wikipedia](https://en.wikipedia.org/wiki/Qt_(software))

[ORACLE](https://docs.oracle.com/cd/E26505_01/html/E26506/glmqp.html)
