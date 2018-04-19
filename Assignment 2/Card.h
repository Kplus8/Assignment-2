#ifndef CARD
#define CARD
#pragma once
#include <iostream>
using namespace std;
class Card
{
public:
	Card() {
		mCardValue = 0;
		mCardName = "";
	}
	~Card() {

	}
	Card(string cardName, int cardValue)
	{
		mCardValue = cardValue;
		mCardName = cardName;

	}
	string getCardName() {
		return mCardName;
	}
	int getCardValue() {
		return mCardValue;
	}
	bool isFaceup() {
		return mIsFaceUp;
	}
	void setFaceup(bool set) {
		mIsFaceUp = set;
	}
private:
	string mCardName;
	int mCardValue;
	bool mIsFaceUp;
};
#endif // !CARD
