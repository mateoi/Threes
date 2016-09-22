#ifndef PLAYER_H
#define PLAYER_H

#include "Card.hpp"
#include "Deck.hpp"
#include "Game.hpp"
#include <vector>


/**
 * Represents a player. Handles user input and holds the player's cards
 */
class Player {
    private:
        std::vector<Card*>* hand; /** The cards in the player's hand */
        std::vector<Card*>* faceUp; /** The visible cards on the table */
        std::vector<Card*>* faceDown; /** The cards on the table that are face down */

        void displayHand(); /** Shows the player's hand on screen */
        int number;
    public:
        bool hasWon(); /** Checks if the player is out of cards */

        /**
         * Given the topmost card in the pile, asks the user for input
         * and returns the cards the user plays. As a side effect, removes the
         * selected cards from the appropriate pile
         */
        std::vector<Card*>* move(Card* onTop);

        /** Draw cards from the pile */
        void draw(std::vector<Card*>* stack);

        /** Adds the given cards to the user's hand */
        void addCards(std::vector<Card*>* cards);

        /** The number of cards in the player's hand */
        inline int handCards() {return hand->size();}

        /** The number of hidden cards */
        inline int faceDownCards() {return faceDown->size();}

        /** Show the player's visible cards */
        void showVisibleCards();

        Player(std::vector<Card*>* h, std::vector<Card*>* u, std::vector<Card*>* d, int n): hand(h), faceUp(u), faceDown(d), number(n) {}
};


#endif
