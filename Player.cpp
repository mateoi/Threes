#include "Player.hpp"
#include <iostream>

using namespace std;

/**
 * Displays a list of cards
 */
void displayCards(vector<Card*>* cards) {
    for (Card* card : *cards) {
        cout << card->toString() << " ";
    }
    cout << endl;
}

/**
 * Display's all the player's cards
 */
void Player::displayHand() {
    cout << "Your hand:" << endl;
    displayCards(hand);
    cout << endl << "Face up cards:" << endl;
    displayCards(faceUp);
    cout << endl << "Face down cards:" << endl;
    for (unsigned int i = 0; i < faceDown->size(); i++)
        cout << "XX ";
    cout << endl;
}

/**
 * Asks the user to play and returns the chosen cards
 */
vector<Card*>* Player::move(Card* onTop) {
    displayHand();
    return new vector<Card*>();
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

