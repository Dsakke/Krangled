#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "IEventTarget.h"

namespace KREN
{
	template<typename... _Types>
	class Event
	{
	public:
		void SubscribeNonInstanced(const std::function<void(_Types...)>& function);

		template<typename _InstanceType>
		void SubscribeInstanced(std::weak_ptr<_InstanceType> pInstance, std::function<void(_InstanceType&, _Types...)> function);

		void Trigger(_Types... types) const;

		void Remove(const std::function<void(_Types...)>& function);

		template<typename _InstanceType>
		void Remove(std::weak_ptr<_InstanceType> pInstance, std::function<void(_InstanceType&, _Types...)> function);

	private:
		std::vector<std::unique_ptr<IEventTarget<_Types...>>> m_Subscribers{  };
	};

	template<typename ..._Types>
	inline void Event<_Types...>::SubscribeNonInstanced(const std::function<void(_Types...)>& function)
	{
		m_Subscribers.push_back(std::unique_ptr<IEventTarget<_Types...>>(reinterpret_cast<IEventTarget<_Types...>*>(new NonInstanceEventTarget<_Types...>{ function })));
	}

	template<typename ..._Types>
	inline void Event<_Types...>::Trigger(_Types ...types) const
	{
		for (int i = 0; i < m_Subscribers.size(); ++i)
		{
			m_Subscribers[i]->TryExecute(types...);
		}
	}
	template<typename ..._Types>
	inline void Event<_Types...>::Remove(const std::function<void(_Types...)>& function)
	{

	};

	template<typename ..._Types>
	template<typename _InstanceType>
	inline void Event<_Types...>::SubscribeInstanced(std::weak_ptr<_InstanceType> pInstance, std::function<void(_InstanceType&, _Types...)> function)
	{
		m_Subscribers.push_back(std::unique_ptr<IEventTarget<_Types...>>(reinterpret_cast<IEventTarget<_Types...>*>(new InstancedEventTarget<_InstanceType, _Types...>{ pInstance, function })));
	};
}