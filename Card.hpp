#ifndef CARD_H
#define CARD_H

#include "Suit.hpp"
#include <string>

class Card {
    private:
        unsigned short value;
        Suit suit;
    public:
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
