#pragma once
#include "Hand.cpp"
class Player
{
public:
	Player();
	~Player();
	virtual int getBet(Hand opponent, int bet2player, bool canRaise, int pot);

protected:
	int mID;
	Hand mHand;
	int mChips;
private:
	void setID(int id);
	int getID();
	void setHand(Hand hand);
	Hand getHand();
	void setChips(int chips);
	int getChips();
};

