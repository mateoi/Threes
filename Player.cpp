#include "Player.hpp"
#include <iostream>

using namespace std;

void Player::displayHand() {
    for (Card card : hand) {
        cout << card.toString() << " ";
    }
    cout << endl;
}

