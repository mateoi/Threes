#ifndef CARD_H
#define CARD_H

#include "Suit.hpp"
#include <string>

/**
 * Represents a single card, composed of a number value and a suit.
 */
class Card {
    private:
        unsigned short value; /** The value of the card */
        Suit suit; /** The card's suit */
    public:
        /**
         * Returns a string representation of this card
         */
	std::string toString() {
            std::string symbol = suit_symbol(suit);
            return std::to_string(value) + symbol;
        }

        Card (unsigned short v, Suit s): value(v), suit(s) {}

        unsigned short getValue() { return value;}
        Suit getSuit() {return suit;}

        bool operator== (Card& other) {
            return (value == other.getValue()) && (suit == other.getSuit());
        }

};

#endif
