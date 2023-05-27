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
##### Compile the file: `g++ example1.cpp -lX11 -o example1`
##### Run the program:  `./example1` 


### References:
[Official Qt(software)](https://wiki.qt.io/Install_Qt_5_on_Ubuntu)

[Qt for Linux/X11](https://doc.qt.io/qt-6/linux.html)

[Qt (software)Wikipedia](https://en.wikipedia.org/wiki/Qt_(software))
