#pragma once
#include <memory>
#include <string>
namespace KREN
{
	// We use the service locator pattern, this will allow the user to easily change what logger is used. 
	// They will also be able to create their own.
	class LoggerService;
	class Logger
	{
	public:
		static void ChangeService(std::unique_ptr<LoggerService>&& pLogger);
		static void LogComment(const std::string& message);
		static void LogWarning(const std::string& message);
		static void LogError(const std::string& message);
	private:
		static std::unique_ptr<LoggerService> m_pLogger;
	};
}