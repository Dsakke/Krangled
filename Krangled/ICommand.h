#pragma once

namespace KREN
{
	class ICommand
	{
	public:
		virtual ~ICommand() = default;

		virtual void Execute() = 0;
	};
}