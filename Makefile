CC=g++
CFLAGS=-Wall -Wpedantic -std=c++11
SOURCES=Game.cpp Player.cpp Suit.cpp Deck.cpp
OBJECTS=$(SOURCES:.cpp=.o)
OUTPUTNAME=game

all: $(SOURCES) $(OUTPUTNAME)

$(OUTPUTNAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUTPUTNAME)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@
