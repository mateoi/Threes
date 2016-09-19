#include "Suit.hpp"

std::string suit_symbol(Suit suit) {
    switch (suit) {
        case SPADES: return "⚔ ";
        case CLUBS: return "♣ ";
        case COINS: return "⛀ ";
        default: return "🍷 ";
    }
}

