#ifndef DECK_H
#define DECK_H

#include <vector>
#include <random>

#include "Card.hpp"

#define NUMBER_OF_DECKS 2

/**
 * Generates a randomly shuffled deck
 */
std::vector<Card*>* generateDeck();

#endif
