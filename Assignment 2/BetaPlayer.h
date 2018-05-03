#ifndef BETA_PLAYER
#define BETA_PLAYER
#pragma once
#include "Player.h"
#include <random>
#include <vector>
class BetaPlayer :
	public Player
{
public:
	BetaPlayer() {

	}
	~BetaPlayer() {

	}
	//NOTE: taken from alpha player and so is partially edited from example code
	int getBet(Hand opponent, int bet2player, vector<Bet> betHistory, bool canRaise, int pot) {
		int bluff = rand() % 10;
		int delta = mHand.evaluateHand() - opponent.evaluateHand();
		int bet = 0;
		int numBets = betHistory.size();
		int potFactor = pot / 10;

		//first 2 rounds
		if (mHand.getCount() < 5) {
			if (numBets == 0) {
				if (delta > 10)
				{
					bet = 10;
				}
				else if (delta > 5)
				{
					bet = 5;
				}
				else if (delta > 0)
				{
					bet = 1;
				}
				else
				{
					bet = 0;
				}
			}
			else {
				if (bet2player == 0) { //previous was a call
					if (delta > 5 - potFactor)
					{
						bet = 10;
					}
					else if (delta > -potFactor)
					{
						bet = 1;
					}
					else
					{
						bet = 0;  //call
					}
				}
				else if (bet2player < (1 + potFactor * 2)) {  //raise within margin
					if (delta > 8 - potFactor)
					{
						bet = bet2player + 10;
					}
					else if (delta > -2 - potFactor)
					{
						bet = bet2player + 1; // 
					}
					else if (delta > -4 - potFactor)
					{
						bet = bet2player;  //call
					}
					else
					{
						bet = 0;  //fold
					}
				}
				else {
					if (delta > 10 - potFactor)
					{
						bet = bet2player + 10;
					}
					else if (delta > -potFactor)
					{
						bet = bet2player + 1;
					}
					else if (delta > -2 - potFactor)
					{
						bet = bet2player; //call
					}
					else
					{
						bet = 0;  //fold
					}
				}
			}
		}

		//last round
		if (mHand.getCount() == 5) {
			if (betHistory.size() == 0) {
				if (delta > 10) {
					bet = bet2player + 10;
				}
				else if (delta > 5) {
					bet = bet2player + 5;
				}
				else {
					bet = 0; //call
				}
			}
			else {
				int potFactor = pot / 10;
				if (bet2player == 0) {
					if (delta > (10 - potFactor)) {
						bet = bet2player + 10;
					}
					else {
						bet = bet2player;
					}
				}
				else if (bet2player < (1 + potFactor * 2)) {
					if (delta > 6 - potFactor) {
						bet = bet2player + 10;
					}
					else if (delta > 2) {
						bet = bet2player; //call
					}
					else {
						bet = 0; //fold
					}
				}
				else {
					if (delta > 8 - potFactor) {
						bet = bet2player + 10;
					}
					else if (delta > 4) {
						bet = bet2player; //call
					}
					else {
						bet = 0; //fold
					}
				}
			}
		}

		if (bluff < 2) { //bluffs 20% of the time (if rand num is 1 or 0, makes max bet possible)
			bet = bet2player + 10;
		}

		if (!canRaise && bet > bet2player) {
			bet = bet2player;
		}
		mChips -= bet;
		return bet;
	}
};
#endif