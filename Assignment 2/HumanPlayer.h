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
	int getBet(Hand opponent, int bet2player, vector<Bet> betHistory, bool canRaise, int pot) {
		Hand displayHand = mHand;//some error prevented mHand from displaying directly
		cout << "You have: " + displayHand.toString() + "and the pot is: "+ to_string(pot) + "\n";
		cout << "You can See: " + opponent.toString() + "from the opponet's Hand" + '\n';
		cout << "You Have: " + to_string(mChips) + " chips. \n";
		int betAmnt = -1;
		cout << "Bet -1 to quit \n";

		if (canRaise) {
			cout << "Enter a bet amount. " + to_string(bet2player) + " is the previous bet." + '\n';
		}

		if (bet2player == 0) {
			cout << "bet 0 to check.\n";
		}

		if (bet2player > 0) {
			cout << "Bet 0 to fold.\n";
		}

		cin >> betAmnt;
		setChips(mChips - betAmnt);
		return betAmnt;
	}
};


#endif // !HUMAN_PLAYER
