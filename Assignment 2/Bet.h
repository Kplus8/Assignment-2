#pragma once
class Bet
{
public:
	Bet() {
		mAmount = 0;
		mPlayer = 0;
	}
	~Bet() {

	}
	Bet(int player, int amount) {
		mAmount = amount;

		mPlayer = player;

	}
	int getPlayer() {
		return mPlayer;
	}
	int getAmount() {
		return mAmount;
	}
	void setAmount(int Bet) {
		mAmount = Bet;
	}
	void setPlayer(int Player) {
		mPlayer = Player;
	}
private:
	int mAmount;
	int mPlayer;
};

