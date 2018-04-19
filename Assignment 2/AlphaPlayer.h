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
	int getBet(Hand opponent, int bet2player, bool canRaise, int pot) const {
		return 0;
	}
};
#endif