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

	HumanPlayer play1;

	if (p1 == ALPHA) {
		AlphaPlayer play1;
	}

	play1.setChips(chips1);
	play1.setID(1);


	int rounds = 20;
	for (rounds; rounds > 0; rounds--) {
		PlayHand(play0, play1);
	}
	return false;
}


bool Game::PlayHand(Player &p1, Player &p2)
{
	deckTop = 0;
	ShuffleDeck();
	p1.setChips(p1.getChips() - 10);
	p2.setChips(p2.getChips() - 10);
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

		BetRound(p1, p2);

	}
	return false;
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
	p1.getBet(p2.getHand().GetVisible(), )

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