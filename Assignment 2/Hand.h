#pragma once
class Hand
{
public:
	Hand();
	~Hand();
	void clearHand();
	void addCard(Card card);
	int getCount();
	Card getCard(int n);
	Hand GetVisible();
	int evaluateHand();
};

