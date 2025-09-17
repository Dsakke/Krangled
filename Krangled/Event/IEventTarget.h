#pragma once
#include <memory>

namespace KRInternal
{
	template<typename... _Types>
	class IEventTarget
	{
	public:
		IEventTarget() = default;
		IEventTarget(const IEventTarget&) = delete;
		IEventTarget(IEventTarget&&) = delete;
		IEventTarget& operator=(const IEventTarget&) = delete;
		IEventTarget& operator=(IEventTarget&) = delete;
		virtual ~IEventTarget() = default;

		virtual void TryExecute(_Types... types) = 0;
		
		virtual bool Compare(const std::weak_ptr<IEventTarget>& eventTarget) const = 0;
	};
}