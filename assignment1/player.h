#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>

class Player
{
private:
	unsigned int m_ID;
	unsigned int m_Rating;
	std::string m_LastName;
	std::string m_FirstName;
	float m_Score;
public:
	Player() : m_ID(0), m_Rating(0), m_Score(0.0)
	{}

	unsigned int GetID() const
	{
		return m_ID;
	}

	void SetID(unsigned int i)
	{
		m_ID = i;
	}

	unsigned int GetRating() const
	{
		return m_Rating;
	}

	void SetRating(unsigned int r)
	{
		m_Rating = r;
	}

	std::string GetLastName() const
	{
		return m_LastName;
	}

	void SetLastName(const std::string& s)
	{
		m_LastName = s;
	}

	std::string GetFirstName() const
	{
		return m_FirstName;
	}

	void SetFirstName(const std::string& s)
	{
		m_FirstName = s;
	}

	float GetScore() const
	{
		return m_Score;
	}

	void SetScore(float f)
	{
		m_Score = f;
	}

	bool operator> (const Player& rhs) const
	{
		return m_Score > rhs.m_Score;
	}

	friend std::istream& operator>>(std::istream& is, Player& p);
	friend std::ostream& operator<<(std::ostream& os, const Player& p);
};

//input operator
std::istream& operator>>(std::istream& is, Player& p)
{
	is >> p.m_ID >> p.m_Rating >> p.m_LastName >> p.m_FirstName >> p.m_Score;
	return is;
}

//output operator
std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << p.m_ID << " " << p.m_Rating << " " << p.m_LastName << " " << p.m_FirstName << " " << p.m_Score;
	return os;
}

#endif // __PLAYER_H__
