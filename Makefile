# Template Makefile
EXECUTABLE = asciidraw
ifeq ($(OS), Windows_NT)
	EXECUTABLE = asciidraw.exe
endif

CXX = g++
CXXFLAGS =
CC = gcc
CFLAGS = -I .
AR = ar
SOURCES = $(wildcard *.cpp) $(wildcard *.c) $(wildcard keyboard/*.cpp) $(wildcard keyboard/*.c)


LINKER_FLAGS = 
#### CONIO CONFIG ####
CFLAGS += -Iconio/
ifneq ($(OS),Windows_NT)
	SOURCES += conio/conio2-ansi.c
else
	SOURCES += conio/conio2-win.c
endif

################

ifeq ($(OS), Windows_NT)
	LINKER_FLAGS += -static
endif
###############
OBJECTS=$(filter %.o, $(SOURCES:.cpp=.o) $(SOURCES:.c=.o))

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@echo Building $@
	@$(CXX) $^ -o $@ $(LINKER_FLAGS)
	@echo
	@echo Type $@ to run.
	@echo

.c.o: 
	@echo Building object: $@
	$(CC) $(CFLAGS) -s -c $< -o $@

.cpp.o: 
	@echo Building object: $@
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	

clean:
	@rm -Rfv */*.o *.o *.a */*.a $(EXECUTABLE) 

info: 
	@echo EXECUTABLE = $(EXECUTABLE)
	@echo CFLAGS = $(CFLAGS)
	@echo LINKER_FLAGS = $(LINKER_FLAGS)
	@echo SOURCES = $(SOURCES)
	@echo OBJECTS = $(OBJECTS)
