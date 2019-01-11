#ifndef DECK_H
#define DECK_H
#include <vector>

enum class Suit
{
	CLUBS,
	SPADES,
	HEARTS,
	DIAMONDS,
	MAX_SUITS
};

enum class Rank
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	MAX_RANKS
};

struct Card
{
	Suit suit;
	Rank rank;
};

class Deck
{
private:
	
	int m_topcard;
public:
	std::vector<Card> m_deck;
	Deck();
	Card deal();
	int randomNumber(int min, int max);
	void reset();
	void shuffle();
};

#endif
