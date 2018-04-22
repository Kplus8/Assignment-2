#ifndef ALPHA_PLAYER
#define ALPHA_PLAYER
#pragma once
#include "Player.h"
#include <vector>
class AlphaPlayer :
	public Player
{
public:
	AlphaPlayer() {

	}
	~AlphaPlayer() {

	}
	int getBet(Hand opponent, int bet2player, vector<Bet> betHistory, bool canRaise, int pot) {
		int delta = mHand.evaluateHand() - opponent.evaluateHand();
		int potFactor = pot / 10;
		//first 2 rounds
		if (mHand.getCount() < 5) {
			if (betHistory.size() == 1) {
				if (delta > 0 && delta <= 5) {
					mChips -= bet2player + 1;
					return bet2player + 1;
				}
				else if (delta > 5 && delta <= 10) {
					mChips -= bet2player + 5;
					return bet2player + 5;
				}
				else if (delta > 10) {
					mChips -= bet2player + 10;
					return bet2player + 10;
				}
				else {
					mChips -= bet2player;
					return bet2player; //call
				}
			}
			else {
				if (betHistory[betHistory.size() - 2].getAmount() == bet2player) { //previous was a call
					if (delta > (0 - potFactor) && delta <= (5 - potFactor)) {
						mChips -= bet2player + 1;
						return bet2player + 1;
					}
					else if (delta > (5 - potFactor)) {
						mChips -= bet2player + 10;
						return bet2player + 10;
					}
					else {
						mChips -= bet2player;
						return bet2player; //call
					}
				}
				else if (betHistory[betHistory.size() - 2].getAmount() < bet2player && bet2player < (1 + potFactor * 2)) { //previous was a raise within margin
					if (delta > -4 - potFactor && delta <= -2 - potFactor) {
						mChips -= bet2player;
						return bet2player; //call
					}
					else if (delta > -2 - potFactor && delta <= 8 - potFactor) {
						mChips -= bet2player + 1;
						return bet2player + 1;
					}
					else if (delta > 8 - potFactor) {
						mChips -= bet2player + 10;
						return bet2player + 10;
					} else {
						return 0; //fold
					}
				}
				else {
					if (delta > -2 - potFactor && delta <= 0 - potFactor) {
						mChips -= bet2player;
						return bet2player; //call
					}
					else if (delta > 0 - potFactor && delta <= 10 - potFactor) {
						mChips -= bet2player + 1;
						return bet2player + 1;
					}
					else if (delta > 10 - potFactor) {
						mChips -= bet2player + 10;
						return bet2player + 10;
					}
					else {
						return 0; //fold
					}
				}
			}
		}

		//last round
		if (mHand.getCount() == 5) {
			if (betHistory.size() == 1) {
				if (delta > 5 && delta <= 10) {
					mChips -= bet2player + 5;
					return bet2player + 5;
				}
				else if (delta > 10) {
					mChips -= bet2player + 10;
					return bet2player + 10;
				}
				else {
					mChips -= bet2player;
					return bet2player; //call
				}
			}
			else {
				int potFactor = pot / 10;
				if (betHistory[betHistory.size() - 2].getAmount() == bet2player) {
					if (delta > (10 - potFactor)) {
						mChips -= bet2player + 10;
						return bet2player + 10;
					} else {
						mChips -= bet2player;
						return bet2player;
					}
				}
				else if (betHistory[betHistory.size() - 2].getAmount() < bet2player && bet2player < (1 + potFactor * 2)) {
					if (delta > 2 - potFactor && delta <= 6 - potFactor) {
						mChips -= bet2player;
						return bet2player; //call
					}
					else if (delta > 6 - potFactor) {
						mChips -= bet2player + 10;
						return bet2player + 10;
					}
					else {
						return 0; //fold
					}
				}
				else {
					if (delta > 4 - potFactor && delta <= 8 - potFactor) {
						mChips -= bet2player;
						return bet2player; //call
					}
					else if (delta > 8 - potFactor) {
						mChips -= bet2player + 10;
						return bet2player + 10;
					}
					else {
						return 0; //fold
					}
				}
			}
		}

		return 0;
	}
};
#endif