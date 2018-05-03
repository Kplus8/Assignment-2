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

	//NOTE: was edited to be more in line with provided example code to ensure code works
	int getBet(Hand opponent, int bet2player, vector<Bet> betHistory, bool canRaise, int pot) {
		Hand displayHand = mHand;//some error prevented mHand from displaying directly
		cout << "\n\n\n" << "You have: " + displayHand.toString() + "and the pot is: "+ to_string(pot) + ".\n";
		cout << "You can See: " + opponent.toString() + "from the opponet's Hand." + '\n';
		cout << "You Have: " + to_string(mChips) + " chips. \n";
		int betAmnt = 0;
		cout << "Bet -1 to quit. You will be reprompted if you bet an illegal amount. \n";
		while (true) {
			int maxPBet = bet2player;
			if (canRaise) {
				maxPBet += 10;
			}
			
			//bet history
			if (betHistory.size() >= 1) {
				cout << endl << "Bet History" << endl;

				for (int i = 0; i < betHistory.size(); i++) {
					cout << "Player: " << betHistory[i].getPlayer() << " Bet: " << betHistory[i].getAmount() << endl;
				}
			}

			if (bet2player > 0) {
				cout << "Bet 0 to fold or bet " << bet2player << " to " << maxPBet << "." << endl;
			} else {
				cout << "Bet 0 to call or bet up to " << maxPBet << " to raise." << endl;
			}
			
			cout << "Enter your bet: ";
			cin >> betAmnt;


			if (betAmnt == 0 || betAmnt == -1 || (betAmnt >= bet2player && betAmnt <= maxPBet)) {
				break;
			}
		}


		setChips(mChips - betAmnt);
		return betAmnt;
	}
};


#endif // !HUMAN_PLAYER
