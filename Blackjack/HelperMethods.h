#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include <string>

namespace Helpers
{
	static int GetRandomNumber(int min, int max)
	{	
		int randNum = min + rand() % max;

		return randNum;
	}

	static std::string CardString(Card* card)
	{
		std::string cardString = "";

		switch (card->GetFace())
		{
		case CardFace::Ace: cardString.append(" Ace");
			break;
		case CardFace::Two: cardString.append(" 2");
			break;
		case CardFace::Three: cardString.append(" 3");
			break;
		case CardFace::Four: cardString.append(" 4");
			break;
		case CardFace::Five: cardString.append(" 5");
			break;
		case CardFace::Six: cardString.append(" 6");
			break;
		case CardFace::Seven: cardString.append(" 7");
			break;
		case CardFace::Eight: cardString.append(" 8");
			break;
		case CardFace::Nine: cardString.append(" 9");
			break;
		case CardFace::Ten: cardString.append(" 10");
			break;
		case CardFace::Jack: cardString.append(" J");
			break;
		case CardFace::Queen: cardString.append(" Q");
			break;
		case CardFace::King: cardString.append(" K");
			break;
		}

		switch (card->GetSuite())
		{
		case CardSuite::Clubs: cardString.append("C");
			break;
		case CardSuite::Diamonds:cardString.append("D");
			break;
		case CardSuite::Spades:cardString.append("S");
			break;
		case CardSuite::Hearts:cardString.append("H");
			break;
		}

		return cardString;
	}
}
