#ifndef PLAYER_H
#define PLAYER_H

#include "Card.hpp"
#include <vector>

using namespace std;

/**
 * Represents a player. Handles user input and holds the player's cards
 */
class Player {
    private:
        vector<Card> hand; /** The cards in the player's hand */
        vector<Card> faceUp; /** The visible cards on the table */
        vector<Card> faceDown; /** The cards on the table that are face down */

        void displayHand(); /** Shows the player's hand on screen */
        int askInput(); /** Asks the user to make a move */
    public:
        bool hasWon(); /** Checks if the player is out of cards */

        /**
         * Given the topmost card in the pile, asks the user for input
         * and returns the card the user plays. As a side effect, removes the
         * selected card from the appropriate pile
         */
        Card move(Card onTop);         

        /** Adds the given cards to the user's hand */
        void addCards(vector<Card> cards);

        Player(vector<Card> h, vector<Card> u, vector<Card> d): hand(h), faceUp(u), faceDown(d) {}
};

#endif
