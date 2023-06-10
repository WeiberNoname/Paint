> ### How can I solve the problem when the program is unable to find an implementation of the library? (OpenCV)
* ##### To link the library against the OpenCV4 :``` pkg-config --libs opencv4 ``` 
> ### How can I fix the memory allocation exception in my C code using Linux debugging? (C)

``` 
gcc -g -o program program.c `pkg-config --cflags --libs opencv4 gtk+-3.0`
gdb ./program
(gdb) run
(gdb) backtrace //gather more information
(gdb) print video_capture.isOpened() //different point
 
