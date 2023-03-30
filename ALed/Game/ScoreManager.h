#pragma once

class ScoreManager
{
public:
	ScoreManager();
	~ScoreManager();

	static ScoreManager* Get();
	void SetScore(int score);
	int GetScore();
	void ResetScore();

protected:
	int m_score;


};

