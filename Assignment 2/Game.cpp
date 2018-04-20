#include "Game.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "Card.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AlphaPlayer.h"
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


	HumanPlayer play0;

	if (p0 == ALPHA) {
		AlphaPlayer play0;

	}

	play0.setChips(chips0);
	play0.setID(0);

	AlphaPlayer play1;

	if (p1 == ALPHA) {
		AlphaPlayer play1;
	}

	play1.setChips(chips1);
	play1.setID(1);


	int rounds = 10;
	for (rounds; rounds > 0; rounds--) {
		PlayHand(play0, play1);
		PlayHand(play1, play0);
	}
	return false;
}


bool Game::PlayHand(Player &p1, Player &p2)
{
	deckTop = 0;
	ShuffleDeck();
	p1.setChips(p1.getChips() - 10);
	p2.setChips(p2.getChips() - 10);
	betHistory.clear();
	betHistory.push_back(Bet(0, 0));
	p1.setHand(Hand());
	p2.setHand(Hand());
	mPot = 20;

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
	BetRound(p1, p2); //bet round 1
	DealNewBid(p1, p2);
	canRaise = true;
	numRaises = 0;
	BetRound(p2, p1); //bet round 2
	DealNewBid(p1, p2);
	canRaise = true;
	numRaises = 0;
	BetRound(p1, p2); //bet round 3

	return false;
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
	int lastBet = betHistory.back().getAmount();
	bool raise = false;
	bool fold = false;
	bool p1Call = false;
	bool p2Call = false;

	//opening bet
	newBet = p1.getBet(p2.getHand().GetVisible(), lastBet, betHistory, canRaise, mPot);
	if (newBet == 0) {
		p1Call = true;
		raise = false;
	} else {
		mPot += newBet;
		raise = true;
		p1Call = false;
		numRaises++;
	}
	betHistory.push_back(Bet(p1.getID(), newBet));
	lastBet = betHistory.back().getAmount();
	//p2 of opening bet
	newBet = p2.getBet(p1.getHand().GetVisible(), lastBet, betHistory, canRaise, mPot);
	// If p1 was a raise////////////////////////////////
	if (p1Call == false) {
		if (newBet == 0) {
			fold = true;
		} else if (newBet == lastBet) {
			p2Call = true;//call
			raise = false;
			mPot += newBet;
		}
		else if (newBet > lastBet) {
			p2Call = false;
			raise = true;//raise
			numRaises++;
			mPot += newBet;
		}
		//end/////////////////////////////////////////
	} else {
		//If p1 was a check///////////////////////////
		if (newBet == 0) {
			p2Call = true;
			raise = false;
		}
		else {
			mPot += newBet;
			raise = true;
			numRaises++;
		}
	}
	betHistory.push_back(Bet(p2.getID(), newBet));
	lastBet = betHistory.back().getAmount();


	while (!fold && (!p1Call || !p2Call)) {
		if (numRaises >= 3) {
			canRaise = false;
		}
		
		
		newBet = p1.getBet(p2.getHand().GetVisible(), lastBet, betHistory, canRaise, mPot);
		// If p2 was a raise////////////////////////////////
		if (p2Call == false) {
			if (newBet == 0) {
				fold = true;
			}
			else if (newBet == lastBet) {
				p1Call = true;//call
				raise = false;
				mPot += newBet;
			}
			else if (newBet > lastBet && canRaise) {
				p1Call = false;
				raise = true;
				numRaises++;
				mPot += newBet;
			}
			//end/////////////////////////////////////////
		}
		else {
			//If p2 was a check///////////////////////////
			if (newBet == 0) {
				p1Call = true;
				raise = false;
			}
			else if(canRaise) {
				mPot += newBet;
				p1Call = false;
				raise = true;
				numRaises++;
			}
		}
		betHistory.push_back(Bet(p1.getID(), newBet));
		lastBet = betHistory.back().getAmount();

		if (!fold && (!p1Call || !p2Call)) {
			if (numRaises >= 3) {
				canRaise = false;
			}


			newBet = p2.getBet(p1.getHand().GetVisible(), lastBet, betHistory, canRaise, mPot);
			// If p1 was a raise////////////////////////////////
			if (p1Call == false) {
				if (newBet == 0) {
					fold = true;
				}
				else if (newBet == lastBet) {
					p2Call = true;//call
					raise = false;
					mPot += newBet;
				}
				else if (newBet > lastBet && canRaise) {
					p2Call = false;
					raise = true;
					numRaises++;
					mPot += newBet;
				}
				//end/////////////////////////////////////////
			}
			else {
				//If p1 was a check///////////////////////////
				if (newBet == 0) {
					p2Call = true;
					raise = false;
				}
				else if (canRaise) {
					mPot += newBet;
					p2Call = false;
					raise = true;
					numRaises++;
				}
			}
			betHistory.push_back(Bet(p2.getID(), newBet));
			lastBet = betHistory.back().getAmount();
		}

	}

	

	return 0;
}

int main() {
	Game playing;

	int p1Choice, p2Choice;
	PlayerType p1;
	PlayerType p2;
	int p1Chips = 1000;
	int p2Chips = 1000;

	cout << "enter 1 if player 1 is Human, and 2 if Alpha AI";
	cin >> p1Choice;
	cout << "enter 1 if player 2 is Human, and 2 if Alpha AI";
	cin >> p2Choice;

	if (p1Choice == 1) {
		p1 = HUMAN;
	}
	else if (p1Choice == 2) {
		p1 = ALPHA;
	}

	if (p2Choice == 1) {
		p2 = HUMAN;
	}
	else if (p2Choice == 2) {
		p2 = ALPHA;
	}

	cout << '\n';
	cin.get();
	playing.playGame(p1, p2, p1Chips, p2Chips, false);
	cin.get();
}