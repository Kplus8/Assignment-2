#pragma once
#include <iostream>
#include <array>
#include <vector>
#include "enum.h"
#include "Player.h"
#include "Card.h"
#include "Bet.h"
class Game
{
public:
	Game();
	~Game();
	bool playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag);
	bool RunGame(bool reportFlag, int & chips0, int & chips1, Player & play0, Player & play1);
	bool mReportFlag;
private:
	int mPot;
	int deckTop;
	vector<Bet> betHistory;
	bool canRaise = true;
	int numRaises = 0;
	array<Card, 52> mDeck;
	bool PlayHand(Player &p1, Player &p2);
	void DealNewBid(Player & p1, Player & p2);
public:
	void ShuffleDeck();
	int BetRound(Player &p1, Player &p2);
};
