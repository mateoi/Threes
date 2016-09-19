#include "Player.hpp"
#include <iostream>

using namespace std;

/**
 * Displays the player's hand
 */
void Player::displayHand() {
    for (Card card : hand) {
        cout << card.toString() << " ";
    }
    cout << endl;
}

