#include <iostream>
#include "Blackjack.h"
#include <time.h>
int main()
{
	srand(time(NULL));

	DeckFactory factory;
	BaseDeck* deck = factory.CreateDeck(DeckType::StandardNoJoker);
	BaseDeck* deck2 = factory.CreateDeck(DeckType::StandardNoJoker);

	std::vector<BaseDeck*> blackjackDeck;
	blackjackDeck.push_back(deck);
	blackjackDeck.push_back(deck2);

	Blackjack* blackjack = new Blackjack(blackjackDeck);

	std::cout << "Enter Number of Players" << std::endl;
	int numOfPlayers;
	std::cin >> numOfPlayers;

	std::cout << "Begin Game" << std::endl;
	blackjack->PlayGame(numOfPlayers);

	for each (auto & deck in blackjackDeck)
	{
		delete deck;
	}

	delete blackjack;

	return 0;
}