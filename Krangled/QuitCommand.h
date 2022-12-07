#pragma once
#include "Command.h"
namespace KREN
{
	class QuitCommand final: public Command
	{
	public:
		QuitCommand(bool& isRunning)
			: m_IsRunning{ isRunning }
		{}

		void Do() override
		{
			m_IsRunning = false;
		}
	private:

		bool& m_IsRunning;
	};
}