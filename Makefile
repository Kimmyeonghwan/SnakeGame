CC = g++
CFLAGS = -std=c++14 -fshort-wchar

LDFLAGS =
LDLIBS = -lncursesw

OBJS = main.o Map.o Item.o

TARGET = main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LDLIBS) $(CFLAGS)

Map.o : Map.cpp Map.h
	$(CC) -c Map.cpp

Item.o : Item.cpp Item.h
	$(CC) -c Item.cpp

main.o : main.cpp
	$(CC) -c main.cpp


clean :
	rm -rf $(TARGET) $(OBJS)
run :
	./$(TARGET)