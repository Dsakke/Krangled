#pragma once
#include "IEventTarget.h"
#include <functional>

template<typename... _Types>
class EventTarget final : IEventTarget<_Types...>
{
public:
	NonInstanceEventTarget(const std::function<void(_Types...)>& function)
		: m_Function{ function }
	{};

	bool TryExecute(_Types... types) override
	{
		m_Function(types...);

		return true;
	}

private:
	std::function<void(_Types...)> m_Function;
};