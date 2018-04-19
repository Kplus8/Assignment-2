#ifndef PLAYER
#define PLAYER


#include <iostream>
#include <string>
#include "Hand.h"
#include "enum.h"
using namespace std;

#pragma once
#include "Hand.h"
class Player
{
public:
	Player() {
		mID = 0;
		mChips = 0;
	}
	~Player() {
	}
	void setID(int id) {
		mID = id;
	}
	int getID() {
		return mID;
	}
	void setHand(Hand hand) {
		mHand = hand;
	}
	Hand getHand() {
		return mHand;
	}
	void setChips(int chips) {
		mChips = chips;
	}
	int getChips() {
		return mChips;
	}
	void addCard(Card card) {
		mHand.addCard(card);
	}

protected:
	int mID;
	Hand mHand;
	int mChips;

public:
	virtual int getBet(Hand opponent, int bet2player, bool canRaise, int pot) const = 0;
};

#endif