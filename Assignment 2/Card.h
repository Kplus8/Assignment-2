#pragma once
class Card
{
public:
	Card();
	~Card();
	Card(string cardName, int cardValue);
	string getCardName();
	int getCardValue();
	bool isFaceup();
	void setFaceup(bool set);
private:
	string mCardName;
	int mCardValue;
	bool mIsFaceUp;
};

