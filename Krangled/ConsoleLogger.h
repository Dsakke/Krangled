#pragma once
#include "LoggerService.h"

class ConsoleLogger final : public LoggerService
{
public:
	void LogComment(const std::string& message) override;
	void LogWarning(const std::string& message) override;
	void LogError(const std::string& message) override;
};