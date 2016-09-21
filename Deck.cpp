#include "Deck.hpp"
using namespace std;

/**
 * Creates an unshuffled deck with numbers from 1 to 12.
 * There are NUMBER_OF_DECKS copies in the produced deck.
 */
vector<Card*>* initDeck() {
    vector<Card*>* deck = new vector<Card*> (NUMBER_OF_DECKS * 12 * 4);
    for (int d = 0; d < NUMBER_OF_DECKS; d++) {
        for (int i = 0; i < 12; i++) {
            int index = (d * 12 * 4) + (i * 4);
            (*deck)[index++] = new Card(i+1, SPADES);
            (*deck)[index++] = new Card(i+1, CLUBS);
            (*deck)[index++] = new Card(i+1, CUPS);
            (*deck)[index] = new Card(i+1, COINS);
        }
    }
    return deck;
}

void moveNelements(vector<Card*>* from, vector<Card*>* to, int n) {
    if (!from->empty() && n > 0) {
        to->push_back(from->back());
        from->pop_back();
        moveNelements(from, to, n-1);
    }
}

/**
 * Randomply shuffles the given deck using the Fisher-Yates shuffle algorithm
 */
void shuffleDeck(vector<Card*>* deck) {
    random_device random;
    for (int i = deck->size() - 1; i > 0; i--) {
        uniform_int_distribution<int> uniform(0, i);
        int exchange = uniform(random);
        Card* temp = (*deck)[i];
        (*deck)[i] = (*deck)[exchange];
        (*deck)[exchange] = temp;
    }
}

/**
 * Generates a randomly shuffled deck
 */
vector<Card*>* generateDeck() {
    vector<Card*>* deck = initDeck();
    shuffleDeck(deck);
    return deck;
}
