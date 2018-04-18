#include "Card.h"
#include <iostream>
#include <string>
using namespace std;


Card::Card()
{
	mCardValue = 0;
}


Card::~Card()
{
}


Card::Card(string cardName, int cardValue)
{
	mCardValue = cardValue;
	mCardName = cardName;

}


string Card::getCardName()
{
	return mCardName;
}


int Card::getCardValue()
{
	return mCardValue;
}


bool Card::isFaceup()
{
	return mIsFaceUp;
}


void Card::setFaceup(bool set)
{
	mIsFaceUp = set;
}
