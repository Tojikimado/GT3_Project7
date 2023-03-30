#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
}

ScoreManager::~ScoreManager()
{
}

ScoreManager* ScoreManager::Get()
{
	static ScoreManager manager;
	return &manager;
}

void ScoreManager::SetScore(int score)
{
	m_score += score;
}

int ScoreManager::GetScore()
{
	return m_score;
}

void ScoreManager::ResetScore()
{
	m_score = 0;
}
