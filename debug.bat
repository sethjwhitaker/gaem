cd obj\debug
g++ -c ..\..\src\*.cpp -std=c++14 -g -Wall -m64 -I ..\..\include -I C:\SDL2-w64\include
cd ..\..
g++ obj\debug\*.o -o bin\debug\main -L C:\SDL2-w64\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
start bin\debug\main