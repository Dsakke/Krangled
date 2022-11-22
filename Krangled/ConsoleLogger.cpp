#include "ConsoleLogger.h"
#include <iostream>

void KREN::ConsoleLogger::LogComment(const std::string& message)
{
	std::cout << "[LOG]: " << message << std::endl;
}

void KREN::ConsoleLogger::LogWarning(const std::string& message)
{
	std::cout << "[WARNING]: " << message << std::endl;
}

void KREN::ConsoleLogger::LogError(const std::string& message)
{
	std::cout << "[ERROR]: " << message << std::endl;
}


