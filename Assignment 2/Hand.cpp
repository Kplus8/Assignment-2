#include "Hand.h"
#include <iostream>
#include <string>
#include "Card.cpp"
using namespace std;


Hand::Hand()
{
	mCount = 0;
	for (int i = 0; i < 5; i++) {
		Card blank("null", 0);
		mCards[i] = blank;
	}
}


Hand::~Hand()
{
}


void Hand::clearHand()
{
	mCount = 0;
	for (int i = 0; i < 5; i++) {
		Card blank("null", 0);
		mCards[i] = blank;
	}
}


void Hand::addCard(Card card)
{
	for (int i = 0; i < 5; i++) {
		if (mCards[i].getCardValue == 0) {
			mCards[i] = card;
			return;
		}
	}
}


int Hand::getCount()
{
	return mCount;
}


Card Hand::getCard(int n)
{
	for (int i = 0; i < 5; i++) {
		return mCards[i];
	}
}


Hand Hand::GetVisible()
{
	Hand show;
	for (int i = 0; i < 5; i++) {
		if (mCards[i].isFaceup()) {
			show.addCard(mCards[i]);
		}
	}
	return show;
}


int Hand::evaluateHand()
{
	int score = 0;
	for (int i = 0; i < 5; i++) {
		score += mCards[i].getCardValue();
	}
	return score;
}
