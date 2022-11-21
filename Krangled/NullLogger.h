#pragma once
#include "LoggerService.h"

// This will be the default logger when no valid logger has been assigned
// The reason we don't just define empty bodies in the base class is because we want the end user to be forced to implement
// all the functions
class NullLogger final : public LoggerService
{
public:
	void LogComment(const std::string& message) override {}
	void LogWarning(const std::string& message) override {}
	void LogError(const std::string& message) override {}
};