#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>

class Game
{
private:
	unsigned int m_WhitePlayerID;
	unsigned int m_BlackPlayerID;
	int m_Score; // 1 = white wins, 0 = draw, -1 = black wins
public:
	Game() : m_WhitePlayerID(0), m_BlackPlayerID(0), m_Score(0.0)
	{}

	unsigned int GetWhitePlayerID() const
	{
		return m_WhitePlayerID;
	}

	unsigned int GetBlackPlayerID() const
	{
		return m_BlackPlayerID;
	}

	float GetScoreForPlayer(unsigned int id) const
	{
		float result = 0.0;
		if (id == m_WhitePlayerID && m_Score == 1)
		{
			result = 1.0;
		}
		else if (id == m_BlackPlayerID && m_Score == -1)
		{
			result = 1.0;
		}
		else if ((id == m_WhitePlayerID || id == m_BlackPlayerID) && m_Score == 0)
		{
			result = 0.5;
		}
		
		return result;
	}

	friend std::istream& operator>>(std::istream& is, Game& g);
	friend std::ostream& operator<<(std::ostream& os, const Game& g);
};

std::istream& operator>>(std::istream& is, Game& g)
{
	is >> g.m_WhitePlayerID >> g.m_BlackPlayerID >> g.m_Score;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Game& g)
{
	os << g.m_WhitePlayerID << " " << g.m_BlackPlayerID << " " << g.m_Score;
	return os;
}

#endif // __GAME_H__
