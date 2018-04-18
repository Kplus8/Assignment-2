#include "Player.h"
#include <iostream>
#include <string>
#include "Hand.cpp"
#include "PlayerType.cpp"
using namespace std;


Player::Player()
{
	mID = 0;
	mChips = 0;
}


Player::~Player()
{
}


void Player::setID(int id)
{
}


int Player::getID()
{
	return 0;
}


void Player::setHand(Hand hand)
{
}


Hand Player::getHand()
{
	return Hand();
}


void Player::setChips(int chips)
{
}


int Player::getChips()
{
	return 0;
}


int Player::getBet(Hand opponent, int bet2player, bool canRaise, int pot)
{
	return 0;
}
