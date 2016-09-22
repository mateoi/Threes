CC=g++
CFLAGS=-Wall -Wpedantic -std=c++11
LINKS=-lcurses
SOURCES=Game.cpp Player.cpp Suit.cpp Deck.cpp Input.cpp
OBJECTS=$(SOURCES:.cpp=.o)
OUTPUTNAME=game

all: $(SOURCES) $(OUTPUTNAME)

$(OUTPUTNAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LINKS) -o $(OUTPUTNAME)
	rm *.o

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@
