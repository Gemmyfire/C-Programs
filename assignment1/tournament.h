#ifndef __TOURNAMENT_H__
#define __TOURNAMENT_H__

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

#include "player.h"
#include "game.h"

class Tournament
{
private:
	std::vector<Player> m_Players;
	std::list<Game> m_Games;
public:
	template<class PlayerInputIterator, class GameInputIterator>
	Tournament(PlayerInputIterator beginPlayer, PlayerInputIterator endPlayer, GameInputIterator beginGame, GameInputIterator endGame)
	{
		// TODO Implement constructor to load m_Players and m_Games without using custom loops
	}

	void GenerateResults(std::ostream& os) const
	{
		// TODO Implement GenerateResults to
		//    1) Calculate each player's score
		//    2) Sort the players by score
		//    3) Write the sorted output to the output stream
		//   All without using custom loops!
	}
};

#endif // __TOURNAMENT_H__
