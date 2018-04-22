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
		cout << "You have: " + displayHand.toString() + "and the pot is: "+ to_string(pot) + ".\n";
		cout << "You can See: " + opponent.toString() + "from the opponet's Hand." + '\n';
		cout << "You Have: " + to_string(mChips) + " chips. \n";
		int betAmnt = -2;
		cout << "Bet -1 to quit. You will be reprompted if you bet an illegal amount. \n";
		while (betAmnt != 0 && betAmnt != -1 && (betAmnt < bet2player || betAmnt > bet2player+10)) {
			if (canRaise) {
				cout << "Enter a bet amount. " + to_string(bet2player) + " is the previous bet." + '\n';
			}


			if (betHistory.size() == 1) {
				cout << "bet 0 to check.\n";
			}
			else {
				cout << "Bet " + to_string(bet2player) + " to call. \n";
			}

			if (bet2player > 0) {
				cout << "Bet 0 to fold.\n";
			}

			cin >> betAmnt;
		}
		setChips(mChips - betAmnt);
		if (betAmnt == -1) {
			exit(0);
		}
		return betAmnt + bet2player;
	}
};


#endif // !HUMAN_PLAYER
