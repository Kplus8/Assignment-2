#ifndef HAND
#define HAND
#pragma once
#include "Card.h"
class Hand
{
public:
	Hand() {
		mCount = 0;
		for (int i = 0; i < 5; i++) {
			Card blank("null", 0);
			mCards[i] = blank;
		}
	}
	~Hand() {

	}
	void clearHand() {
		mCount = 0;
		for (int i = 0; i < 5; i++) {
			Card blank("null", 0);
			mCards[i] = blank;
		}
	}
	void addCard(Card card) {
		for (int i = 0; i < 5; i++) {
			if (mCards[i].getCardValue() == 0) {
				mCards[i] = card;
				return;
			}
		}
	}
	int getCount() {
		return mCount;
	}
	Card getCard(int n) {
		return mCards[n];
	}
	Hand GetVisible() {
		Hand show;
		for (int i = 0; i < 5; i++) {
			if (mCards[i].isFaceup()) {
				show.addCard(mCards[i]);
			}
		}
		return show;
	}
	int evaluateHand() {
		int score = 0;
		for (int i = 0; i < 5; i++) {
			score += mCards[i].getCardValue();
		}
		return score;


	}
	string toString() {
		string out = "";
		for (int i = 0; i < mCount; i++) {
			out += mCards[i].getCardName() + " ";
		}
		return out;
	}
private:
	Card mCards[5];
	int mCount;
};


#endif // !HAND
