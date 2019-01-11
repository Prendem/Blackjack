#ifndef HAND_H
#define HAND_H
#include "Deck.h"
#include <iostream>

class Hand
{
private:
	std::vector<Card> m_hand;
	bool m_isdealer;
	bool m_hasace;
	bool m_hasvisibleace;
public:
	Hand(Card a, Card b, bool isdealer);
	int maxScore();
	int visibleMaxScore();
	int minScore();
	int visibleMinScore();
	friend void printTurn(Hand &player, Hand &dealer);
	friend void printTurnEnd(Hand &player, Hand &dealer);
	friend void operator+(Hand &hand, Card card);
};

#endif
