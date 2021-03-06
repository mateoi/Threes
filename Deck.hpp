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
/**
 * Move cards between vectors
 */
void moveNelements(std::vector<Card*>* from, std::vector<Card*>* to, int n);
/** Sort a vector of cards */
void sortCards(std::vector<Card*>* vec);
#endif
