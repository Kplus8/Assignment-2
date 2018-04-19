#pragma once
class Bet
{
public:
	Bet();
	~Bet();
	Bet(int, int);
	int getPlayer();
	int getAmount();
private:
	int mAmount;
	int mPlayer;
};

