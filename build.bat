g++ -c src\*.cpp -std=c++14 -O3 -Wall -m64 -I include -I C:\SDL2-w64\include
g++ *.o -o bin\release\main -L C:\SDL2-w64\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image