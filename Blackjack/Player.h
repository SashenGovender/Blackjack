#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Card.h"

class Player
{
private:
	std::vector<Card*> mCards;

public:
	Player() {};
	~Player();
	void AddPlayerCard(Card* card);
	int PlayerScore();
	std::string PlayerCards(bool showOnlyFirstCard = false);
};

#endif // PLAYER_H
