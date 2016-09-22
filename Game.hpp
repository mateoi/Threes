#ifndef GAME_H
#define GAME_H

#include "Card.hpp"
#include "Deck.hpp"
#include "Input.hpp"
#include "Player.hpp"
#include <iostream>
#include <unistd.h>
#include <term.h>

/** Checks whether the given value can be played over the value currently on top. */
bool canPlay(unsigned short value, unsigned short onTop);

#endif
