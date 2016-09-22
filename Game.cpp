#include "Game.hpp"
using namespace std;

vector<Card*>* pile = new vector<Card*>();
vector<Card*>* stack = generateDeck();
Player** players;
int numberOfPlayers;

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
    moveNelements(stack, vec, amount);
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
        int lastValue = pile->back()->getValue();
        bool isKnave = lastValue == 10;
        bool isPoker = checkPoker(lastValue);
        return isKnave || isPoker;
    }
    return false;
}

/**
 * Prints information about the game's current status
 */
void printStatus(Card* onTop) {
    if (onTop)
        cout << "The card on top is " << onTop->toString() << endl << endl;
    else
        cout << "The pile is empty." << endl << endl;
}

/**
 * Clears the screen
 */
void clearScreen() {
    if (!cur_term) {
        int result;
        setupterm(NULL, STDOUT_FILENO, &result);
        if (result <= 0) return;
    }
    putp(tigetstr("clear"));
}

/**
 * Print information about the players
 */
void printPlayerInfo(int turn) {
    cout << "There are " << stack->size() << " card(s) left in the stack." << endl;
    cout << "There are " << pile->size() << " card(s) in the pile." << endl << endl;
    cout << "  ";
    string spaces = "        ";
    for (int i = 0; i < numberOfPlayers; i++) {
        if (i == turn)
            cout << "  You   " << spaces;
        else
            cout << "Player " << i+1 << spaces;
    }
    cout << endl << "  ";
    for (int i = 0; i < numberOfPlayers; i++)
        cout << "--------" << spaces;
    cout << endl << "  ";
    for (int i = 0; i < numberOfPlayers; i++) {
        int hand = players[i]->handCards();
        cout << "Hand: " << (hand < 10 ? " " : "") << hand << spaces;
    }
    cout << endl << "  ";
    for (int i = 0; i < numberOfPlayers; i++)
        cout << "Hidden:" << players[i]->faceDownCards() << spaces;
    cout << endl << " ";
    for (int i = 0; i < numberOfPlayers; i++) {
        players[i]->showVisibleCards();
        cout << "    ";
    }
    cout << endl << endl;
}

/**
 * Print info about a new turn
 */
void printNewTurn(int turn) {
    clearScreen();
    cout << "Player " << turn+1 << "'s turn." << endl;
}

/**
 * Main game loop. Goes through each player and handles discards and other game events
 */
int playGame() {
    int turn = 0;
    printNewTurn(0);
    while (true) {
        Player p = *(players[turn]);
        Card* onTop = pile->empty() ? nullptr : pile->back();
        printStatus(onTop);
        vector<Card*>* played = p.move(onTop);
        if (p.hasWon()) return turn;
        if (played->empty()) {
            removeThrees();
            p.addCards(pile);
        } else {
            moveNelements(played, pile, played->size());
            p.draw(stack);
            if (discard()) {
                cout << "Discard!" << endl;
                cout << "---------------------------------------------" << endl;
                pile->clear();
                delete played;
                continue; // If the play is a discard, the player repeats their turn.
            }
        }
        delete played;
        ++turn %= numberOfPlayers;
        printNewTurn(turn);
        pauseProgram();
    }
}

/**
 * Checks if the given card value is a valid card to play over the card
 * currently on top of the pile
 */
bool canPlay(unsigned short value, unsigned short onTop) {
    switch (onTop) {
    case 1: return (value >= 1 && value <= 3) || value == 10;
    case 2: return true;
    case 3: return value == 3;
    case 7: return (value >= 2 && value <= 7) || value == 10;
    case 10: return false;  // This case shouldn't really happen.
    default: return value >= onTop || (value >= 1 && value <= 3) || value == 10;
    };
}

int main() {
    numberOfPlayers = askNumberOfPlayers();
    players = new Player*[numberOfPlayers];
    for (int i = 0; i < numberOfPlayers; i++) {
        players[i] = new Player(newCards(3), newCards(3), newCards(3), i);
    }
    int winner = playGame();
    cout << "Game over! Player " << winner+1 << " is the winner!" << endl;
}
