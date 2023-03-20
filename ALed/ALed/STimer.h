#pragma once

class STimer
{
public:
    static bool s_isPerformanceTimer;
    static float s_initTime;
    static float s_frequency;
    static long long s_performTime;
    static float s_deltaTime;
    static float s_timeScale;

    static void InitSystemTime();
    static float GetSystemTimeEx();
    static void UpdateDeltaTime();
private:
    static float s_timeUpdate;

};