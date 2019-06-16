#include "Player.h"
#include "HelperMethods.h"

Player::~Player()
{
	for each (auto & card in mCards)
	{
		delete card;
	}
}

void  Player::AddPlayerCard(Card* card)
{
	mCards.push_back(card);
}

int  Player::PlayerScore()
{
	int sum = 0;
	bool ace11Used = false;

	for each (auto & card in mCards)
	{
		int cardValue = card->GetValue();
		if (card->GetFace() == CardFace::Ace)
		{
			if (sum + 11 <= 21)
			{
				cardValue = 11;
				ace11Used = true;
			}
		}
		sum += cardValue;
	}

	if (sum > 21 && ace11Used)
	{
		sum -= 10;
	}
		

	return sum;
}

std::string  Player::PlayerCards(bool showOnlyFirstCard)
{
	std::string playerStringCards = "";
	for each (auto & card in mCards)
	{
		playerStringCards.append(Helpers::CardString(card));

		if (showOnlyFirstCard) break;
	}

	return playerStringCards;
}

