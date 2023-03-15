#pragma once

class IntersectData
{
public:
	IntersectData(bool _doesIntersect, float _distance);

	bool GetDoesIntersect();

	float GetDistance();

private:
	bool m_doesIntersect;
	float m_distance;
};

