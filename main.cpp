#include "pch.h"      //comment out if not using precompiled headers
#include <iostream>
#include "Hand.h"

bool dealerHit(Hand &player, Hand &dealer, bool playerstanding)
{
	if (player.maxScore() > 21)
		return false;
	if (playerstanding && player.maxScore() > dealer.maxScore())
		return true;
	if (playerstanding && player.maxScore() < dealer.maxScore())
		return false;
	if (dealer.maxScore() > 16)
		return false;
	return true;
}

int main()
{
	Deck deck;
	while (true)
	{
		Hand player(deck.deal(), deck.deal(), false);
		Hand dealer(deck.deal(), deck.deal(), true);
		bool playerstanding{ false };
		bool dealerstanding{ false };
		while (true)
		{
			printTurn(player, dealer);
			if (!playerstanding)
			{
				std::cout << "Enter \"h\" to hit and \"s\" to stand: ";
				char action;
				std::cin >> action;
				if (action == 'H' || action == 'h')
					player + deck.deal();
				if (action == 'S' || action == 's')
					playerstanding = true;
			}

			if (player.maxScore() > 21)
			{
				std::cout << "\n";
				printTurnEnd(player, dealer);
				std::cout << "You bust, dealer wins" << std::endl;
				break;
			}
			
			if (!dealerstanding)
			{
				bool dealerhit{ dealerHit(player, dealer, playerstanding) };
				if (dealerhit)
					dealer + deck.deal();
				else
					dealerstanding = true;
			}

			if (dealer.maxScore() > 21)
			{
				std::cout << "\n";
				printTurnEnd(player, dealer);
				std::cout << "Dealer busts, you win" << std::endl;
				break;
			}

			if (playerstanding && dealerstanding)
			{
				std::cout << "\n";
				printTurnEnd(player, dealer);

				if (player.maxScore() > dealer.maxScore())
				{
					std::cout << "You win" << std::endl;
					break;
				}

				if (player.maxScore() < dealer.maxScore())
				{
					std::cout << "Dealer wins" << std::endl;
					break;
				}

				if (player.maxScore() == dealer.maxScore())
				{
					std::cout << "You draw" << std::endl;
					break;
				}
			}

			std::cout << "\n";
		}

		std::cout << "Play again (y/n): ";
		char playagain;
		std::cin >> playagain;
		if (playagain == 'N' || playagain == 'n')
			break;
		std::cout << "\n";
	}

	return 0;
}
