shortestPaths:  shortestPaths.o
        g++ -o shortestPaths shortestPaths.o

shortestPaths.o:        shortestPaths.cpp
        g++ -c shortestPaths.cpp

clean :
        rm *.o a.out shortestPaths
