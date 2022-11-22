#include "Logger.h"
#include "LoggerService.h"
#include "NullLogger.h"

std::unique_ptr<KREN::LoggerService> KREN::Logger::m_pLogger{ std::make_unique<NullLogger>() };

void KREN::Logger::ChangeService(std::unique_ptr<KREN::LoggerService>&& pLogger)
{
	if (pLogger)
	{
		m_pLogger = std::move(pLogger);
		return;
	}

	m_pLogger = std::make_unique<NullLogger>();
}

void KREN::Logger::LogComment(const std::string& message)
{
	m_pLogger->LogComment(message);
}

void KREN::Logger::LogWarning(const std::string& message)
{
	m_pLogger->LogWarning(message);
}

void KREN::Logger::LogError(const std::string& message)
{
	m_pLogger->LogError(message);
}


