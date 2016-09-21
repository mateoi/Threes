CC=g++
CFLAGS=-Wall -Wpedantic -std=c++11
SOURCES=Game.cpp Player.cpp Suit.cpp Deck.cpp Input.cpp
OBJECTS=$(SOURCES:.cpp=.o)
OUTPUTNAME=game

all: $(SOURCES) $(OUTPUTNAME)

$(OUTPUTNAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUTPUTNAME)
	rm *.o

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@
