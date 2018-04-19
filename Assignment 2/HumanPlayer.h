#ifndef HUMAN_PLAYER
#define HUMAN_PLAYER
#pragma once
#include "Player.h"
class HumanPlayer :
	public Player
{
public:
	HumanPlayer() {

	}
	~HumanPlayer() {

	}
	int getBet(Hand opponent, int bet2player, bool canRaise, int pot) const {
		return 0;
	}
};


#endif // !HUMAN_PLAYER
