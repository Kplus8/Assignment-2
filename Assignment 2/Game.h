
class Game
{
public:
	Game();
	~Game();
	bool playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag);
private:
	int mPot;
	Card mDeck[52];
	bool mReportFlag;
	Player mPlayer;
	bool PlayHand(Player &p1, Player &p2);
public:
	void ShuffleDeck();
	int BetRound(Player &p1, Player &p2);
};
