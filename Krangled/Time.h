#pragma once
#include "Singleton.h"
#include <chrono>
namespace KREN
{
	class Time final : public Singleton<Time>
	{
	public:
		void UpdateTime(); // I want to figure out a way to not expose this as much, the end user should not be able to update this
		float GetElapsedTime() const;
	private:
		friend class Singleton<Time>;
		Time();

		std::chrono::high_resolution_clock::time_point m_PrevTime;
		// ElapsedTime in seconds 
		float m_ElapsedTime;
	
	};
}