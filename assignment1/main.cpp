#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "tournament.h"

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Usage:  assignment01 [player input file] [game input file] [output file]" << std::endl;
		return 0;
	}

	std::ifstream finPlayers(argv[1]);
	std::ifstream finGames(argv[2]);
	std::ofstream fout(argv[3]);

	std::istream_iterator<Player> beginPlayer(finPlayers);
	std::istream_iterator<Player> endPlayer;
	std::istream_iterator<Game> beginGame(finGames);
	std::istream_iterator<Game> endGame;

	Tournament tournament(beginPlayer, endPlayer, beginGame, endGame);
	tournament.GenerateResults(fout);

	return 0;
}
