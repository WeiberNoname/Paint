# Paint

> ## C_PLUS_Version

|Qt Application design|
| --- | 
|  Qt, It is an open source cross platform designed for software development, the main purpose is involving `Graphical User Interfaces` application that displays the GUIs from software design, and has been classified as widget toolkit, and also supports for non-GUI programs like command line tools. This development maintains various compilers including the `GCC`,  `VScode`, etc.(Cross platform : `Linux, Windows, macOS`) |
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

### References:
[Official Qt(software)](https://wiki.qt.io/Install_Qt_5_on_Ubuntu)

[Qt for Linux/X11](https://doc.qt.io/qt-6/linux.html)

[Qt (software)Wikipedia](https://en.wikipedia.org/wiki/Qt_(software))
