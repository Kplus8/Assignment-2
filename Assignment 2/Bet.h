#pragma once
class Bet
{
public:
	Bet();
	~Bet();
	Bet(int player, int amount);
	int getPlayer();
	int getAmount();
private:
	int mAmount;
	int mPlayer;
};

