#include "Game.h"
#include <iostream>
#include <algorithm>
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

	HumanPlayer play1;

	if (p1 == ALPHA) {
		AlphaPlayer play1;
	}

	int rounds = 20;
	for (rounds; rounds > 0; rounds--) {
		PlayHand(play0, play1);
	}
	return false;
}


bool Game::PlayHand(Player &p1, Player &p2)
{
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
	random_shuffle(mDeck.begin(), mDeck.end());

	for (int i = 0; i < 52; i++) {
		cout << mDeck[i].getCardName() + '\n';
	}
}


int Game::BetRound(Player &p1, Player &p2)
{
	return 0;
}

int main() {
	Game playing;

	playing.ShuffleDeck();
	cin.get();
}