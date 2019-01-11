#include "pch.h"    //comment out if not using precompiled headers
#include "Deck.h"
#include <cstdlib>
#include <ctime>

Deck::Deck() : m_topcard{ 0 }
{
	m_deck.resize(52);
	for (int suit{0}; suit < 4; ++suit)
		for (int rank{ 0 }; rank < 13; ++rank)
		{
			m_deck[m_topcard].suit = static_cast<Suit>(suit);
			m_deck[m_topcard].rank = static_cast<Rank>(rank);
			++m_topcard;
		}
	srand(std::time(0));
	rand();
	shuffle();
	m_topcard = 0;
}

int Deck::randomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

void Deck::shuffle()
{
	Card temp;
	for (int index{ 0 }; index < 52; ++index)
	{
		int randomindex{ randomNumber(0,51) };
		temp = m_deck[index];
		m_deck[index] = m_deck[randomindex];
		m_deck[randomindex] = temp;
	}
}

Card Deck::deal()
{
	Card temp = m_deck[m_topcard];
	++m_topcard;
	return temp;
}

void Deck::reset()
{
	m_topcard = 0;
	shuffle();
}
