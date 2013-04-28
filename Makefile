CC = g++
CFLAGS = -c -Wall -std=c++11
LIBS = -lpthread
APPLICATION = libnetwork
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)

all:$(OBJECTS)
	@echo done

$(OBJECTS):%.o:%.cpp
	$(CC) $(CFLAGS) $(LIBS) $< -o $@

.PHONY : clean
clean : 
	rm $(OBJECTS)


