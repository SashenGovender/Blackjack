#include <iostream>
#include "Blackjack.h"
#include "HelperMethods.h"

Blackjack::Blackjack(std::vector<BaseDeck*> blackjackDeck)
{
	mBlackjackDeck = blackjackDeck;

	for each (auto & deck in mBlackjackDeck)
	{
		deck->ShuffleDeck();
	}

	mDealer = new Player();
}

Blackjack::~Blackjack()
{
	for each (auto & player in mPlayers)
	{
		delete player;
	}
	delete mDealer;
}

void Blackjack::PlayGame(int numPlayers)
{
	InitialisePlayers(numPlayers);

	std::cout << "\nDeal" << std::endl;
	Deal();

	std::cout << "Players Cards " << std::endl;
	DisplayPlayerHands();

	std::cout << "Dealer Cards: "<< mDealer->PlayerCards(true) << std::endl;
	std::cout << "End of Deals Round" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	std::cout << "\nTime to Hit" << std::endl;
	PlayersHit();
	std::cout << "End of Player Round Hitting" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	if (!ShouldProceedToDealerTurn())
	{
		std::cout << "\nAll Players Bust" << std::endl;
		std::cout << "Dealer Wins" << std::endl;
		return;
	}

	std::cout << "\nDealers Turn" << std::endl;
	DealerHit();
	std::cout << "End of Dealers Turn" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	std::cout << "\nGame Results" << std::endl;
	PlayerVsDealerResult();

}

void Blackjack::InitialisePlayers(int numPlayers)
{
	for (int player = 0; player < numPlayers; player++)
	{
		mPlayers.push_back(new Player());
	}
}

void Blackjack::DisplayPlayerHands()
{
	for (int playerIndex = 0; playerIndex < mPlayers.size(); playerIndex++)
	{
		std::cout << "Player " << playerIndex + 1 <<": "<<mPlayers.at(playerIndex)->PlayerCards() << " - Score: " << mPlayers.at(playerIndex)->PlayerScore() << std::endl;
	}
}

void Blackjack::PlayersHit()
{
	for (int playerIndex = 0; playerIndex < mPlayers.size(); playerIndex++)
	{
		Player* player = mPlayers.at(playerIndex);
		std::cout << "\nPlayer " << playerIndex + 1 << " Score: " << player->PlayerScore() << std::endl;

		int hit = 0;
		while (player->PlayerScore() < 21)
		{
			std::cout << "Should Hit ?" << std::endl;
			std::cin >> hit;
			if (hit)
			{
				Hit(player);
				std::cout << "Cards: " << mPlayers.at(playerIndex)->PlayerCards() << std::endl;
				std::cout << "Score: " << player->PlayerScore() << std::endl;
			}
			else
			{
				break;
			}
		}
	}
}

void Blackjack::DealerHit()
{
	std::cout << "Cards: " << mDealer->PlayerCards() << std::endl;
	std::cout << "Score: " << mDealer->PlayerScore() << std::endl;
	while (mDealer->PlayerScore() <= 17)
	{
		Hit(mDealer);
		std::cout << "Cards: " << mDealer->PlayerCards() << std::endl;
		std::cout << "Score: " << mDealer->PlayerScore() << std::endl;
	}
}

void Blackjack::PlayerVsDealerResult()
{
	for (int playerIndex = 0; playerIndex < mPlayers.size(); playerIndex++)
	{
		Player* player = mPlayers.at(playerIndex);
		if (player->PlayerScore() > 21)
		{
			std::cout << "Dealer Wins against Player " << playerIndex + 1 <<std::endl;
		}
		else if (mDealer->PlayerScore() > 21)
		{
			std::cout << "Player " << playerIndex + 1 << " Wins" << std::endl;
		}
		else if (mDealer->PlayerScore() > player->PlayerScore())
		{
			std::cout << "Dealer Wins against Player " << playerIndex + 1 << std::endl;
		}
		else if (mDealer->PlayerScore() < player->PlayerScore())
		{
			std::cout << "Player " << playerIndex + 1 << " Wins" << std::endl;
		}
		else
		{
			std::cout << "Tie against Player " << playerIndex + 1 << std::endl;
		}
	}
}

void Blackjack::Deal()
{
	for each (auto & player in mPlayers)
	{
		player->AddPlayerCard(GetCard());
		player->AddPlayerCard(GetCard());
	}

	mDealer->AddPlayerCard(GetCard());
	mDealer->AddPlayerCard(GetCard());
}

void Blackjack::Hit(Player* player)
{
	player->AddPlayerCard(GetCard());
}

void Blackjack::Stand(Player* player)
{

}

void Blackjack::Split(Player* player)
{

}

bool Blackjack::ShouldProceedToDealerTurn()
{
	for each (auto & player in mPlayers)
	{
		if (player->PlayerScore() <= 21)
		{
			return true;
		}
	}
	return false;
}

Card* Blackjack::GetCard()
{
	//only 1 deck can be empty at  a time
	for (int deckIndex = 0; deckIndex < mBlackjackDeck.size();deckIndex++)
	{
		if (mBlackjackDeck.at(deckIndex)->GetCards().size() == 0)
		{
			mBlackjackDeck.erase(mBlackjackDeck.begin() + deckIndex);
			break;
		}
	}

	if (!mBlackjackDeck.size())
		 throw std::runtime_error("Insufficent Cards");// how to handle this? TODO

	int deckNumber = Helpers::GetRandomNumber(0, mBlackjackDeck.size() - 1);

	return mBlackjackDeck.at(deckNumber)->GetTopCard();
}
