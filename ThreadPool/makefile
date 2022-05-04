CC = g++
CFLAGS = -g -Wall -std=c++11

Main:Main.o TaskQueue.o ThreadPool.o
    $(CC)  Main.o TaskQueue.o ThreadPool.o -o Main
Main.o:Main.cpp
    $(CC) $(CFLAGS)  -c Main.cpp -o Main.o
TaskQueue.o:TaskQueue.cpp
    $(CC) $(CFLAGS) -c TaskQueue.cpp -o TaskQueue.o
ThreadPool.o:ThreadPool.cpp
    $(CC) $(CFLAGS) -c ThreadPool.cpp -o ThreadPool.o
clean:
    rm -rf *.o