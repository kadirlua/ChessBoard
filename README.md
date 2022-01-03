# ChessBoard
Chess game with calculating white and black pieces points. It's written in modern C++(14 and later). I have tested the codes on Windows and Linux. Use test files to test the app (board1.txt, board2.txt, board3.txt).

# Compile
You can use Visual Studio or CMake to compile the project. </br>

### Compiling for Windows
Open the ChessBoard.sln file and compile the project or use CMake tool. The test files must be in the same directory with the executable file (.exe)

### Compiling for Linux
- Create build directory and change to directory
```
  mkdir build
  cd build
```
- copy test files to build directory. (board1.txt, board2.txt, board3.txt)
- build cmake and run
```
  cmake ..
  make
  ./ChessBoard
```
