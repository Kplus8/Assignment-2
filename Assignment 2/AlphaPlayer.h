#ifndef ALPHA_PLAYER
#define ALPHA_PLAYER
#pragma once
#include "Player.h"
class AlphaPlayer :
	public Player
{
public:
	AlphaPlayer() {

	}
	~AlphaPlayer() {

	}
	int getBet(Hand opponent, int bet2player, vector<Bet> betHistory, bool canRaise, int pot) {
		return 10;
	}
};
#endif