#include "Logger.h"
#include "LoggerService.h"
#include "NullLogger.h"

std::unique_ptr<LoggerService> Logger::m_pLogger{ std::make_unique<NullLogger>() };

void Logger::ChangeService(std::unique_ptr<LoggerService>&& pLogger)
{
	if (pLogger)
	{
		m_pLogger = std::move(pLogger);
		return;
	}

	m_pLogger = std::make_unique<NullLogger>();
}

void Logger::LogComment(const std::string& message)
{
	m_pLogger->LogComment(message);
}

void Logger::LogWarning(const std::string& message)
{
	m_pLogger->LogWarning(message);
}

void Logger::LogError(const std::string& message)
{
	m_pLogger->LogError(message);
}


