Random notes:
// Color GDB with GDB Dashboard
https://stackoverflow.com/questions/209534/how-to-highlight-and-color-gdb-output-during-interactive-debugging

// GCC: GNU Compiler Collection
g++: GNU C++ Compiler
gcc: GNU C   Compiler

// How to build c++ 11
$ clang++  -std=c++11
$ g++ -std=c++11 file.cpp
or
$ g++ -std=c++0x file.cpp

e.g
(gdb) b main
(gdb) r
(gdb) set directories // Will search for .cpp file in $cwd and $cdir

http://www.rapidtables.com/code/linux/gcc/gcc-o.htm

I forgot that g++ is the command to be used to compile c++ code. 
You're supposed to use that. GCC is today the GNU C Collection, 
// How to debug: $gdb ./$MY_BINARY_NAME
// (gdb) break main
// (gdb) n
// (gdb) s
// (gdb) info locals 
// (gdb) list
// (gdb) c


- Upgraded gdb to version 7.8
https://askubuntu.com/questions/529781/upgrade-from-gdb-7-7-to-7-8


