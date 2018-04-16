#pragma once
class Player
{
public:
	Player();
	~Player();
	int getBet(Hand opponent, int bet2player, bool canRaise, int pot);
	void setID(int id);
	int getID();
	void setHand(Hand hand);
	Hand getHand();
	void setChips(int chips);
	int getChips();
};

