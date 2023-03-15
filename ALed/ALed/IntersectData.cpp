#include "IntersectData.h"

IntersectData::IntersectData(bool _doesIntersect, float _distance)
    : m_doesIntersect(_doesIntersect), m_distance(_distance){}

bool IntersectData::GetDoesIntersect()
{
    return m_doesIntersect;
}

float IntersectData::GetDistance()
{
    return m_distance;
}
