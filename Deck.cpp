#include "Deck.hpp"
using namespace std;

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

vector<Card*>* generateDeck() {
    vector<Card*>* deck = initDeck();
    shuffleDeck(deck);
    return deck;
}
