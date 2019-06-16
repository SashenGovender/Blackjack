#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "Deck.h"

class Blackjack
{
private:
	std::vector<Player*> mPlayers;
	Player* mDealer;
	std::vector<BaseDeck*> mBlackjackDeck;

	Card* GetCard();
	bool ShouldProceedToDealerTurn();
	void InitialisePlayers(int numPlayers);
	void DisplayPlayerHands();
	void PlayersHit();
	void DealerHit();
	void PlayerVsDealerResult();

public:
	Blackjack(std::vector<BaseDeck*> blackjackDeck);
	~Blackjack();
	void PlayGame(int numPlayers);
	void Deal();
	void Hit(Player* player);
	void Stand(Player* player);
	void Split(Player* player);
};

#endif // BLACKJACK_H

