#include "Suit.hpp"

/** Returns a string representation of a Suit */
std::string suit_symbol(Suit suit) {
    switch (suit) {
        case SPADES: return "⚔ "; // Sword emoji
        case CLUBS: return "♣ "; // Club emoji
        case COINS: return "⛀ "; // Coin emoji
        default: return "🍷 "; // Wine glass emoji
    }
}

