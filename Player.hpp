#ifndef PLAYER_H
#define PLAYER_H

#include "Card.hpp"
#include <vector>

using namespace std;
class Player {
    private:
        vector<Card> hand;
        vector<Card> faceUp;
        vector<Card> faceDown;

        void displayHand();
        int askInput();
    public:
        bool hasWon();
        Card move(Card onTop);
        void addCards(vector<Card> cards);

        Player(vector<Card> h, vector<Card> u, vector<Card> d): hand(h), faceUp(u), faceDown(d) {}
};

#endif
