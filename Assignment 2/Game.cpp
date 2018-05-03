#include "Game.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "Card.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AlphaPlayer.h"
#include "BetaPlayer.h"
#include "enum.h"
using namespace std;


Game::Game()
{
}


Game::~Game()
{
}

bool Game::playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag)
{
	mReportFlag = reportFlag;
	if (p0 == HUMAN && p1 == ALPHA) {
		HumanPlayer play0;
		AlphaPlayer play1;
		play0.setChips(chips0);
		play1.setChips(chips1);
		play1.setID(1);
		return RunGame(reportFlag, chips0, chips1, play0, play1);

	} else if (p0 == ALPHA && p1 == ALPHA) {
		AlphaPlayer play0;
		AlphaPlayer play1;
		play0.setChips(chips0);
		play1.setChips(chips1);
		play1.setID(1);
		return RunGame(reportFlag, chips0, chips1, play0, play1);
	} else if (p0 == HUMAN && p1 == BETA) {
		HumanPlayer play0;
		BetaPlayer play1;
		play0.setChips(chips0);
		play1.setChips(chips1);
		play1.setID(1);
		return RunGame(reportFlag, chips0, chips1, play0, play1);
	} else if (p0 == ALPHA && p1 == BETA) {
		AlphaPlayer play0;
		BetaPlayer play1;
		play0.setChips(chips0);
		play1.setChips(chips1);
		play1.setID(1);
		return RunGame(reportFlag, chips0, chips1, play0, play1);
	}
	else if (p1 == ALPHA && p0 == BETA) {
		AlphaPlayer play1;
		BetaPlayer play0;
		play0.setChips(chips0);
		play1.setChips(chips1);
		play1.setID(1);
		return RunGame(reportFlag, chips0, chips1, play0, play1);
	}

	return false;
}

bool Game::RunGame(bool reportFlag, int & chips0, int & chips1, Player &play0, Player &play1)
{
	int rounds = 10;
	for (rounds; rounds > 0; rounds--) {
		if (mReportFlag) {
			cout << "Next Round\n"; \
		}
		bool quit = PlayHand(play0, play1);
		if (quit == true) {
			return true;
		}
		if (mReportFlag) {
			cout << "Next Round\n";
		}
		quit = PlayHand(play1, play0);
		if (quit == true) {
			return true;
		}
	}

	if (mPot >= 0) {
		play1.setChips(play1.getChips() + mPot / 2);
		play0.setChips(play0.getChips() + mPot / 2);
		mPot = 0;
	}

	if (reportFlag) {
		cout << "Game Finished. Player 0 had: " << play0.getChips() << " chips and Player 1 had " << play1.getChips() << " chips." << endl;
	}
	chips0 = play0.getChips();
	chips1 = play1.getChips();
	return false;
}


bool Game::PlayHand(Player &p1, Player &p2)
{
	bool quit = false;
	deckTop = 0;
	ShuffleDeck();
	p1.setChips(p1.getChips() - 10);
	p2.setChips(p2.getChips() - 10);
	betHistory.clear();
	p1.setHand(Hand());
	p2.setHand(Hand());
	mPot += 20;

	for (int i = 0; i < 3; i++, deckTop+=2) {
		Card p1Deal = mDeck[deckTop];
		if (i == 0) {
			p1Deal.setFaceup(false);
		}
		else {
			p1Deal.setFaceup(true);
		}
		
		Card p2Deal = mDeck[deckTop + 1];
		if (i == 0) {
			p2Deal.setFaceup(false);
		}
		else {
			p2Deal.setFaceup(true);
		}
		

		p1.addCard(p1Deal);
		p2.addCard(p2Deal);
	}
	canRaise = true;
	numRaises = 0;

	//NOTE: was edited to be more in line with provided example code to ensure code works
	for (int round = 0; round < 3; round++) {
		int result = BetRound(p1, p2);
		if (result == -2) {
			quit = true;
			break;
		}

		if (result >= 0) {
			if (mReportFlag) {
				cout << "Player " << (1 - result) << " folded. The pot was " << mPot << "." << endl;
			}
			if (result == p1.getID()) {
				p1.setChips(p1.getChips() + mPot);
			}
			else {
				p2.setChips(p2.getChips() + mPot);
			}
			mPot = 0;
			break;
		}

		if (round < 2) {
			DealNewBid(p1, p2);
		} else {
			int p1score = p1.getHand().evaluateHand();
			int p2score = p2.getHand().evaluateHand();
			if (mReportFlag) {
				if (p1score > p2score) {
					cout << "Player " << p1.getID() << " won the hand with a pot of " << mPot << endl;
					p1.setChips(p1.getChips() + mPot);
					mPot = 0;
				}
				else if (p2score > p1score) {
					cout << "Player " << p2.getID() << " won the hand with a pot of " << mPot << endl;
					p2.setChips(p2.getChips() + mPot);
					mPot = 0;
				}
				else {
					cout << "It was a tie, the pot will carry over." << endl;
				}
			}
		}

	}

	return quit;
}

void Game::DealNewBid(Player & p1, Player & p2)
{
	Card p1Deal = mDeck[deckTop];
	p1Deal.setFaceup(true);

	Card p2Deal = mDeck[deckTop + 1];
	p2Deal.setFaceup(true);

	p1.addCard(p1Deal);
	p2.addCard(p2Deal);
	deckTop += 2;
}


void Game::ShuffleDeck()
{
	//population
	int loc = 0;
	Card hold("Ace", 1);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = hold;
	}
	Card hold2("Two", 2);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = hold2;
	}
	Card hold3("Three", 3);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = hold3;
	}
	Card hold4("Four", 4);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = hold4;
	}
	Card hold5("Five", 5);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = hold5;
	}
	Card hold6("Six", 6);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = hold6;
	}
	Card hold7("Seven", 7);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = hold7;
	}
	Card hold8("Eight", 8);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = hold8;
	}
	Card hold9("Nine", 9);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = hold9;
	}
	Card hold10("Ten", 10);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = hold10;
	}
	Card holdJack("Jack", 10);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = holdJack;
	}
	Card holdQueen("Queen", 10);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = holdQueen;
	}
	Card holdKing("King", 10);
	for (int i = 0; i < 4; i++, loc++) {
		mDeck[loc] = holdKing;
	}

	//shuffle
	unsigned seed = (int)std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(mDeck.begin(), mDeck.end(), default_random_engine(seed));

	//for (int i = 0; i < 52; i++) {
	//	cout << mDeck[i].getCardName() + '\n';
	//}
}


int Game::BetRound(Player &p1, Player &p2)
{
	int output = 0;
	int newBet = 0;
	int bet2player = 0;
	canRaise = true;
	bool raise = false;
	bool fold = false;
	bool p1Call = false;
	bool p2Call = false;

	//NOTE: was edited to be more in line with provided example code to ensure code works
	while (true) {
		
		//first player
		newBet = p1.getBet(p2.getHand().GetVisible(), bet2player, betHistory, canRaise, mPot);

		if (newBet == -1) {
			return -2;
		}

		betHistory.push_back(Bet(p1.getID(), newBet));

		//if not call or raise
		if (newBet < bet2player) {
			return p2.getID();
		}

		mPot += newBet;
		bet2player = newBet - bet2player;

		//if a call
		if (bet2player == 0) {
			break;
		} else {
			numRaises++;
			if (numRaises >= 3) {
				canRaise = false;
			}
		}
		
		//second player
		newBet = p2.getBet(p1.getHand().GetVisible(), bet2player, betHistory, canRaise, mPot);

		if (newBet == -1) {
			return -2;
		}

		betHistory.push_back(Bet(p2.getID(), newBet));

		//if not call or raise
		if (newBet < bet2player) {
			return p1.getID();
		}

		mPot += newBet;
		bet2player = newBet - bet2player;

		//if a call
		if (bet2player == 0) {
			break;
		}
		else {
			numRaises++;
			if (numRaises >= 3) {
				canRaise = false;
			}
		}

	}

	return -1;
}

int main() {
	Game playing;

	int p1Choice, p2Choice;
	bool report = true;
	int betaCounter = 0;
	int betaTests = 100;
	PlayerType p1;
	PlayerType p2;
	int p1Chips = 1000;
	int p2Chips = 1000;
	cout << "Choosing the alpha for p1, and the beta for p2, will show the results of 100 consecutive matches." << endl << endl;
	cout << "enter 1 if player 1 is Human, 2 if Alpha: ";
	cin >> p1Choice;
	cout << "enter 2 if player 2 is Alpha, and 3 if Beta: ";
	cin >> p2Choice;

	if (p1Choice == 1) {
		p1 = HUMAN;
		report = true;
	}
	else if (p1Choice == 2) {
		p1 = ALPHA;
		report = false;
	}

	if (p2Choice == 2) {
		p2 = ALPHA;
	}
	else if (p2Choice == 3) {
		p2 = BETA;
	}

	cout << '\n';
	cin.get();
	if (p1 == ALPHA && p2 == BETA) {
		for (int j = 0; j < betaTests; j++) {
			p1Chips = 1000;
			p2Chips = 1000;
			for (int i = 0; i < 100; i++) {
				playing.playGame(p2, p1, p2Chips, p1Chips, report);
			}
			if (p1Chips < p2Chips) {
				betaCounter++;
			}
			cout << "Game Finished. Alpha Player had: " << p1Chips << " chips and Beta player had " << p2Chips << " chips." << endl;
		}

		cout << "The Beta AI won " << betaCounter << " games out of " << betaTests;
	}
	else {
		playing.playGame(p1, p2, p1Chips, p2Chips, report);
	}
	cin.get();
	return 0;
}