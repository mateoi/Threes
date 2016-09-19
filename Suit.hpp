#ifndef SUIT_H
#define SUIT_H

#include <string>

/** An enum of the four suits in the Spanish deck */
enum Suit {SPADES, CLUBS, COINS, CUPS};
std::string suit_symbol(Suit suit);

#endif
