#pragma once
#include "ICommand.h"
namespace KREN
{
	class QuitCommand final: public ICommand
	{
	public:
		QuitCommand(bool& isRunning)
			: m_IsRunning{ isRunning }
		{}

		void Execute() override
		{
			m_IsRunning = false;
		}
	private:

		bool& m_IsRunning;
	};
}