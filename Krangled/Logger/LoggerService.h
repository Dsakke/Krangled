#pragma once
#include <string>

namespace KREN
{
	class LoggerService
	{
	public:
		virtual ~LoggerService() = default;

		virtual void LogComment(const std::string& message) = 0;
		virtual void LogWarning(const std::string& message) = 0;
		virtual void LogError(const std::string& message) = 0;
	private:
	};
}