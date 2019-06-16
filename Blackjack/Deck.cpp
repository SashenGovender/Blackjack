#include "Deck.h"
#include "HelperMethods.h"

//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

std::vector<Card> BaseDeck::GetCards() const
{
	return mCards;
}

void BaseDeck::AddCard(Card& val)
{
	mCards.push_back(val);
}

Card* BaseDeck::GetTopCard()
{
	Card* card = nullptr;
	if (mCards.size())
	{
		card = new Card(mCards.back());
		mCards.pop_back();
	}

	return card;
}

void BaseDeck::ShuffleDeck(int times)
{
	for (int iterations = 1; iterations <= times; iterations++)
	{
		for (int k = 0; k < mCards.size(); k++)
		{
			int randNum1 = Helpers::GetRandomNumber(0, mCards.size());
			int randNum2 = Helpers::GetRandomNumber(0, mCards.size());

			if (randNum1 != randNum2)
			{
				std::swap(mCards.at(randNum1), mCards.at(randNum2));
			}
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

StandardDeck::StandardDeck()
{
	for (int cardFace = (int)CardFace::Ace; cardFace <= (int)CardFace::King; cardFace++)
	{
		for (int cardSuite = (int)CardSuite::Hearts; cardSuite <= (int)CardSuite::Clubs; cardSuite++)
		{
			int value = cardFace;
			if ((CardFace)cardFace >= CardFace::Jack && (CardFace)cardFace <= CardFace::King)
			{
				value = 10;
			}
			Card card((CardFace)cardFace, (CardSuite)cardSuite, value);
			AddCard(card);
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

BaseDeck* DeckFactory::CreateDeck(DeckType deckType)
{
	switch (deckType)
	{
	case DeckType::StandardNoJoker:
	{
		return new StandardDeck();
	}
	break;
	}
	return nullptr;
}

//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

