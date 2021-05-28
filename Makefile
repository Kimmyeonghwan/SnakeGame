CXX				:= g++
CXXFLAGS 		:= -std=c++14 -Wextra -g -lncursesw

SRC				:= src
INCLUDE			:= include

SRCEXT			:= cpp

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
SOURCEDIRS	:= $(SRC)
INCLUDEDIRS	:= $(INCLUDE)
LIBDIRS		:= $(LIB)
else
EXECUTABLE	:= main.o
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)
LIBDIRS		:= $(shell find $(LIB) -type d)
endif

BUILDDIR	:= build

CXXINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
CXXLIBS		:= $(patsubst %,-L%, $(LIBDIRS:%/=%))

SOURCES		:= $(wildcard $(patsubst %,%/*.$(SRCEXT), $(SOURCEDIRS)))
OBJECTS		:= $(patsubst $(SOURCEDIRS)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

.PHONY: clean
clean:
	-$(RM) $(SRC)/$(EXECUTABLE)
	-$(RM) $(OBJECTS)

run: clean
	$(CXX) $(SOURCES) $(CXXINCLUDES) $(CXXFLAGS) -o build/main.o && ./build/main.o