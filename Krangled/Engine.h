#pragma once

namespace KREN
{
	class Engine
	{
	public:
		void Init();
		void Run();
		void Clean();

	private:
		float m_FixedUpdateTimer;
		float m_FixedUpdateInterval = 1.f / 60.f;
	};
}