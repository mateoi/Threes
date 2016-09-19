#include "Game.hpp"
using namespace std;

int main() {
    vector<Card*>* deck = generateDeck();
    for (Card* card : *deck) {
        cout << card->toString() << endl;
    }
}
