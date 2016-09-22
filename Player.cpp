#include "Player.hpp"
#include <iostream>

using namespace std;

/**
 * Displays a list of cards
 */
void displayCards(vector<Card*>* cards, bool showIndex) {
    int i = 1;
    cout << "┌────┬──────┐" << endl;
    for (Card* card : *cards) {
        cout << "│ ";
        if (showIndex) {
            cout << i << (i < 10 ? "  " : " ");
            i++;
        } else {
            cout << "   ";
        }
        cout << "│ " << card->toString();
        cout << (card->getValue() < 10 ? "  │" : " │") << endl;
    }
    cout << "└────┴──────┘" << endl;
}

/**
 * Display's all the player's cards
 */
void Player::displayHand() {
    cout << "Your hand:" << endl;
    displayCards(hand, true);
    cout << endl << "Face up cards:" << endl;
    displayCards(faceUp, hand->empty());
    cout << endl << "Face down cards:" << endl;
    for (unsigned int i = 0; i < faceDown->size(); i++) {
        if (hand->empty() && faceUp->empty())
            cout << " " << i+1 << ": ";
        cout << "XX ";
    }
    cout << endl;
}

/**
 * Gets the cards with the given indices from the given vector.
 * Indices start at one, not zero.
 */
vector<Card*>* getCards(vector<int>* move, vector<Card*>* vec) {
    vector<Card*>* result = new vector<Card*>();
    for (int i : *move) {
        if (i == 0 || (unsigned int) i > vec->size()) {
            result->clear();
            break;
        }
        result->push_back((*vec)[i-1]);
    }
    return result;
}

/**
 * Removes the given cards from the given vector
 */
void removeCards(vector<Card*>* toRemove, vector<Card*>* vec) {
    for (Card* card : *toRemove) {
        for (unsigned int i = 0; i < vec->size(); i++) {
            if ((*vec)[i] == card) {
                vec->erase(vec->begin() + i);
                break;
            }
        }
    }
}

/**
 * Checks whether all the given cards have the same value
 */
bool allSame(vector<Card*>* cards) {
    if (cards->empty()) return true;
    int value = (*cards)[0]->getValue();
    for (Card* card : *cards) {
        if (card->getValue() != value) return false;
    }
    return true;
}

/**
 * Checks whether the given cards are a valid move given the card on top
 */
bool isValidMove(vector<Card*>* cards, Card* onTop) {
    if (cards->empty() || onTop == nullptr) return true;
    bool same = allSame(cards);
    bool valid = canPlay((*cards)[0]->getValue(), onTop->getValue());
    return same && valid;
}

/**
 * Asks the user to play and returns the chosen cards
 */
vector<Card*>* Player::move(Card* onTop) {
    displayHand();
    vector<Card*>* inPlay =  hand->size() != 0 ? hand :
                             faceUp->size() != 0 ? faceUp :
                             faceDown;
    vector<Card*>* cards = new vector<Card*>();
    if (inPlay == faceDown) {
	cout << "What card do you want to play? ";
        int choice = userInput(1, faceDown->size()) - 1;
        Card* card = (*faceDown)[choice];
        faceDown->erase(faceDown->begin() + choice);
        cout << "You played " << card->toString() << "!" << endl;
        if (onTop == nullptr || canPlay(card->getValue(), onTop->getValue())) {
            cout << "Success!" << endl;
            cards->push_back(card);
        } else {
            cout << "Oh no!" << endl;
            hand->push_back(card);
        }
        pauseProgram();
    } else {
        cout << "Enter the cards you want to play, or 0 to take all the cards: ";
        vector<int>* move = userMultiInput(0, inPlay->size());
        while (!isValidMove(getCards(move, inPlay), onTop)) {
            cout << "That is not a valid move. Enter cards: ";
            move = userMultiInput(0, inPlay->size());
        }
        cards = getCards(move, inPlay);
        delete move;
        removeCards(cards, inPlay);
    }
    return cards;
}

/**
 * Checks whether the player has won the game
 */
bool Player::hasWon() {
    return hand->empty() && faceUp->empty() && faceDown->empty();
}

/**
 * Adds the given cards to the player's hand
 */
void Player::addCards(std::vector<Card*>* cards) {
    moveNelements(cards, hand, cards->size());
}

/**
 * Draws cards from the given stack until the user has 3 cards or the stack is empty
 */
void Player::draw(vector<Card*>* stack) {
    moveNelements(stack, hand, 3 - hand->size());
}

