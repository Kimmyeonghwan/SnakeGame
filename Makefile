CC = g++
CFLAGS = -std=c++14 -fshort-wchar

LDFLAGS =
LDLIBS = -lncursesw

OBJS = UI.o main.o Map.o

TARGET = main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LDLIBS) $(CFLAGS)

UI.o : UI.cpp UI.h
	$(CC) -c UI.cpp

Map.o : Map.cpp Map.h
	$(CC) -c Map.cpp

main.o : main.cpp
	$(CC) -c main.cpp

clean :
	rm -rf $(TARGET) $(OBJS)
run :
	./$(TARGET)