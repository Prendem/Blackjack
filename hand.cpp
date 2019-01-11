#include "pch.h"      //comment out if not using precompiled headers
#include "Hand.h"

Hand::Hand(Card a, Card b, bool isdealer) : m_hand{a,b}, m_isdealer{isdealer}, m_hasvisibleace{false}, m_hasace{false}
{
	if (a.rank == Rank::ACE || b.rank == Rank::ACE)
		m_hasace = true;
	if (m_isdealer && m_hasace && a.rank == Rank::ACE)
		m_hasvisibleace = true;
}

int Hand::maxScore()
{
	if (!m_hasace || minScore() + 10 > 21)
		return minScore();
	else
		return minScore() + 10;
}

int Hand::visibleMaxScore()
{
	if (!m_hasvisibleace || visibleMinScore() + 10 > 21)
		return visibleMinScore();
	else
		return visibleMinScore() + 10;
}

int Hand::minScore()
{
	int score{ 0 };
	for (Card card : m_hand)
	{
		if (static_cast<int>(card.rank) < 9)
			score += (static_cast<int>(card.rank) + 2);
		if (card.rank == Rank::JACK || card.rank == Rank::QUEEN || card.rank == Rank::KING)
			score += 10;
		if (card.rank == Rank::ACE)
			score += 1;
	}
	return score;
}

int Hand::visibleMinScore()
{
	int score{ 0 };
	for (int index{ 0 }; index < m_hand.size(); ++index)
	{
		if (index != 1)
		{
			if (static_cast<int>(m_hand[index].rank) < 9)
				score += (static_cast<int>(m_hand[index].rank) + 2);
			if (m_hand[index].rank == Rank::JACK || m_hand[index].rank == Rank::QUEEN || m_hand[index].rank == Rank::KING)
				score += 10;
			if (m_hand[index].rank == Rank::ACE)
				score += 1;
		}
	}
	return score;
}

void operator+(Hand &hand, Card card)
{
	int handsize = hand.m_hand.size();
	hand.m_hand.resize(handsize + 1);
	hand.m_hand[handsize] = card;
	if (hand.m_hand[handsize].rank == Rank::ACE)
		hand.m_hasace = true;
}

void printCard(Card &card)
{
	switch (card.rank)
	{
	case Rank::TWO:
		std::cout << "2";
		break;
	case Rank::THREE:
		std::cout << "3";
		break;
	case Rank::FOUR:
		std::cout << "4";
		break;
	case Rank::FIVE:
		std::cout << "5";
		break;
	case Rank::SIX:
		std::cout << "6";
		break;
	case Rank::SEVEN:
		std::cout << "7";
		break;
	case Rank::EIGHT:
		std::cout << "8";
		break;
	case Rank::NINE:
		std::cout << "9";
		break;
	case Rank::TEN:
		std::cout << "T";
		break;
	case Rank::JACK:
		std::cout << "J";
		break;
	case Rank::QUEEN:
		std::cout << "Q";
		break;
	case Rank::KING:
		std::cout << "K";
		break;
	case Rank::ACE:
		std::cout << "A";
		break;
	}

	switch (card.suit)
	{
	case Suit::CLUBS:
		std::cout << "C, ";
		break;
	case Suit::DIAMONDS:
		std::cout << "D, ";
		break;
	case Suit::HEARTS:
		std::cout << "H, ";
		break;
	case Suit::SPADES:
		std::cout << "S, ";
		break;
	}
}

void printTurn(Hand &player, Hand &dealer)
{
	std::cout << "The dealer is showing:\n";
	printCard(dealer.m_hand[0]);
	if (dealer.m_hand.size() == 2)
		std::cout << "and ";
	std::cout << "an obscured card, ";
	for (int index{ 2 }; index < dealer.m_hand.size(); ++index)
		printCard(dealer.m_hand[index]);
	std::cout << "giving a visible score of " << dealer.visibleMinScore();
	if (dealer.visibleMinScore() != dealer.visibleMaxScore())
		std::cout << " or " << dealer.visibleMaxScore();
	std::cout << "\n\n";

	std::cout << "You have:\n";
	for (Card card : player.m_hand)
		printCard(card);
	std::cout << "giving a total score of " << player.minScore();
	if (player.minScore() != player.maxScore())
		std::cout << " or " << player.maxScore();
	std::cout << "\n";

}

void printTurnEnd(Hand &player, Hand &dealer)
{
	std::cout << "The dealer has:\n";
	for (Card card : dealer.m_hand)
		printCard(card);
	std::cout << "giving a total score of " << dealer.minScore();
	if (dealer.minScore() != dealer.maxScore())
		std::cout << " or " << dealer.maxScore();
	std::cout << "\n\n";
	
	std::cout << "You have:\n";
	for (Card card : player.m_hand)
		printCard(card);
	std::cout << "giving a total score of " << player.minScore();
	if (player.minScore() != player.maxScore())
		std::cout << " or " << player.maxScore();
	std::cout << "\n";
}
