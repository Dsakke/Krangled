#pragma once
#include "Time.h"

Time::Time()
	:m_PrevTime{ std::chrono::high_resolution_clock::now() }
	, m_ElapsedTime{0.f}
{
}

void Time::UpdateTime()
{
	std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
	std::chrono::milliseconds elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_PrevTime);
	m_ElapsedTime = float(elapsedMs.count()) / 1000;
}

float Time::GetElapsedTime() const
{
	return m_ElapsedTime;
}
