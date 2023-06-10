> ### The static library for C in C++
#### Compile `g++ -c calculation.cpp`
#### Static library `ar rcs libcalculation.a calculation.o`
#### Compile with static library `gcc main.c -L. -lstdc++ -lcalculation -o program`
#### Run program `./program`
