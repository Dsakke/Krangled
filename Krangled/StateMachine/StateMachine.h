#pragma once
#include <unordered_map>
#include "State.h"
#include "../Logger/Logger.h"

namespace KREN
{
	template<typename _StateKey, typename... _Parameters>
	class StateMachine 
	{
		
	public:
		typedef _StateKey StateKey;
		StateMachine& operator=(const StateMachine& other) = default;
		StateMachine(const StateMachine& other) = default;
		StateMachine& operator=(StateMachine&& other);
		StateMachine(StateMachine&& other);


		void AddState(const StateKey& stateKey, State<_StateKey, _Parameters...>&& state);
		void AddState(const StateKey& stateKey, const State<_StateKey, _Parameters...>& state);

		StateKey GetCurrentState(); 
		void Update(const _Parameters&... parameters);
	private:
		std::unordered_map<StateKey, State<_StateKey, _Parameters...>> m_States;
		StateKey m_CurrentState;
	};

	template<typename _StateKey, typename ..._Parameters>
	inline StateMachine<_StateKey, _Parameters...>& StateMachine<_StateKey, _Parameters...>::operator=(StateMachine&& other)
	{
		m_States = other.m_States;
		m_CurrentState = other.m_CurrentState;
	}

	template<typename _StateKey, typename ..._Parameters>
	inline StateMachine<_StateKey, _Parameters...>::StateMachine(StateMachine<_StateKey, _Parameters...>&& other)
		: m_States{std::move(other.m_States)}
		, m_CurrentState{other.m_CurrentState}
	{
	}

	template<typename _StateKey, typename ..._Parameters>
	inline void StateMachine<_StateKey, _Parameters...>::AddState(const StateKey& stateKey, State<_StateKey, _Parameters...>&& state)
	{
		auto iterator = m_States.find(stateKey);
		if (iterator != m_States.end())
		{
			Logger::LogError("Multiple states with same key registered");
			return;
		}

		m_States[stateKey] = std::move(state);
	}

	template<typename _StateKey, typename ..._Parameters>
	inline void StateMachine<_StateKey, _Parameters...>::AddState(const StateKey& stateKey, const State<_StateKey, _Parameters...>& state)
	{
		auto iterator = m_States.find(stateKey);
		if (iterator != m_States.end())
		{
			Logger::LogError("Multiple states with same key registered");
			return;
		}

		m_States[stateKey] = state;
	}

	template<typename _StateKey, typename ..._Parameters>
	inline StateMachine<_StateKey, _Parameters...>::StateKey StateMachine<_StateKey, _Parameters...>::GetCurrentState()
	{
		return m_CurrentState;
	}

	template<typename _StateKey, typename ..._Parameters>
	inline void StateMachine<_StateKey, _Parameters...>::Update(const _Parameters&... parameters)
	{
		State<StateKey, _Parameters...>& currentState = m_States[m_CurrentState];
		std::optional<StateKey> newState = currentState.ShouldTransition(parameters...);
		if (newState.has_value())
		{
			m_CurrentState = newState.value();
		}
	}
}