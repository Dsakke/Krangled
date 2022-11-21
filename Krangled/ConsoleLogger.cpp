#include "ConsoleLogger.h"
#include <iostream>

void ConsoleLogger::LogComment(const std::string& message)
{
	std::cout << "[LOG]: " << message << std::endl;
}

void ConsoleLogger::LogWarning(const std::string& message)
{
	std::cout << "[WARNING]: " << message << std::endl;
}

void ConsoleLogger::LogError(const std::string& message)
{
	std::cout << "[ERROR]: " << message << std::endl;
}


