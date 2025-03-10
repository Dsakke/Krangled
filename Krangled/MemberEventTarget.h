#pragma once
#include "IEventTarget.h"
#include <memory>
#include <functional>

namespace KRInternal
{
	template<typename _InstanceType, typename... _Types>
	class MemberEventTarget final : IEventTarget<_Types...>
	{
	public:
		MemberEventTarget(std::weak_ptr<_InstanceType> pInstance, const std::function<void(_InstanceType&, _Types...)>& function);

		bool TryExecute(_Types... types) override;

		bool Compare(const std::weak_ptr<IEventTarget<_Types...>>& eventTarget) const override;

	private:
		std::weak_ptr<_InstanceType> m_pInstance;
		std::function<void(_InstanceType&, _Types...)> m_Function;
	};

	template<typename _InstanceType, typename... _Types>
	MemberEventTarget<_InstanceType, _Types...>::MemberEventTarget(std::weak_ptr<_InstanceType> pInstance, const std::function<void(_InstanceType&, _Types...)>& function)
		: m_pInstance{ pInstance }
		, m_Function{ function }
	{};

	template<typename _InstanceType, typename... _Types>
	bool MemberEventTarget<_InstanceType, _Types...>::TryExecute(_Types... types)
	{
		std::shared_ptr<_InstanceType> pInstance = m_pInstance.lock();
		if (!pInstance)
		{
			return false;
		}

		m_Function(*pInstance, types...);
	}
	template<typename _InstanceType, typename ..._Types>
	inline bool MemberEventTarget<_InstanceType, _Types...>::Compare(const std::weak_ptr<IEventTarget<_Types...>>& eventTarget) const
	{
		auto pShared = eventTarget.lock();
		if (!pShared)
		{
			return false;
		}

		auto pMemberEventTarget = std::dynamic_pointer_cast<MemberEventTarget, IEventTarget<_Types...>>();
		if (!pMemberEventTarget)
		{
			return false;
		}

		if (pMemberEventTarget->m_pInstance != m_pInstance)
		{
			return false;
		}

		return pMemberEventTarget->m_Function == m_Function;
	};
}
