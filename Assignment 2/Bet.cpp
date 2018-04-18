#include "Bet.h"



Bet::Bet()
{
	mAmount = 0;
	mPlayer = 0;
}


Bet::~Bet()
{
}


Bet::Bet(int player, int amount)
{
	mAmount = amount;

	mPlayer = player;

}


int Bet::getPlayer()
{
	return mPlayer;
}


int Bet::getAmount()
{
	return mAmount;
}
