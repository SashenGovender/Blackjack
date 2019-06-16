#ifndef CARD_H
#define CARD_H

enum class CardFace
{
	Ace = 1,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
};

enum class CardSuite
{
	Hearts,
	Diamonds,
	Spades,
	Clubs,
};

class Card
{
private:
	CardFace mFace;
	CardSuite mSuite;
	int mValue;

public:
	Card(CardFace face, CardSuite suite, int value) :mFace(face), mSuite(suite), mValue(value) { };
	int GetValue() const { return mValue; }
	void SetValue(int val) { mValue = val; }
	CardSuite GetSuite() const { return mSuite; }
	void SetSuite(CardSuite val) { mSuite = val; }
	CardFace GetFace() const { return mFace; }
	void SetFace(CardFace val) { mFace = val; }
};

#endif // define CARD_H
