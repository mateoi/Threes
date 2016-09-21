#include "Game.hpp"
using namespace std;

vector<Card*>* pile;
vector<Card*>* stack = generateDeck();
Player** players;

/**
 * Ask how many players will play the game
 */
int askNumberOfPlayers() {
    cout << "Please enter the number of players" << endl;
    return userInput(2, 5);
}

/**
 * Draws a given amount of cards from the stack and creates a new vector of cards
 */
vector<Card*>* newCards(int amount) {
    vector<Card*>* vec = new vector<Card*>();
    moveNelements(pile, vec, amount);
    return vec;
}

/**
 * Removes all the threes from the top of the pile
 */
void removeThrees() {
    while (!pile->empty() && pile->back()->getValue() == 3)
        pile->pop_back();
}

/**
 * Checks whether the topmost cards in the pile form a poker
 * (four different suits of the same value)
 */
bool checkPoker(int lastValue) {
    int value = 0;
    int index = pile->size() - 1;
    while (index >= 0 && (*pile)[index]->getValue() == lastValue) {
        value |= (1 << (*pile)[index]->getSuit());
        index--;
    }
    return value == 0xF;  // 1111 in binary
} 

/**
 * Checks whether the pile should be discarded if there is a poker or a knave on top of the pile.
 */
bool discard() {
    if (!pile->empty()) {
        int lastValue = stack->back()->getValue();
        bool isKnave = lastValue == 10;
        bool isPoker = checkPoker(lastValue);
        return isKnave || isPoker;
    }
    return false;
}

/**
 * Main game loop. Goes through each player and handles discards and other game events
 */
int playGame(int numberOfPlayers) {
    int turn = 0;
    while (true) {
        Player p = *(players[turn]);
        cout << "Player " << turn << "'s turn." << endl << endl;
        vector<Card*>* played = p.move(pile->empty() ? nullptr : pile->back());
        if (p.hasWon()) return turn;
        if (played->empty()) {
            removeThrees();
            p.addCards(pile);
        } else {
            moveNelements(played, pile, played->size());
            p.draw(stack);
            if (discard()) {
                pile->clear();
                continue; // If the play is a discard, the player repeats their turn.
            }
        }
        ++turn %= numberOfPlayers;
    }
}

int main() {
    int numberOfPlayers = askNumberOfPlayers();
    players = new Player*[numberOfPlayers];
    for (int i = 0; i < numberOfPlayers; i++) {
        players[i] = new Player(newCards(3), newCards(3), newCards(3));
    }
    int winner = playGame(numberOfPlayers);
    cout << "Game over! Player " << winner << " is the winner!" << endl;
}
