#pragma once
#include <functional>
#include <vector>
#include "StateTransition.h"
#include <optional>

namespace KREN
{
	template<typename _StateKey, typename... _Parameters>
	class State
	{
	public:
		typedef _StateKey StateKey;
		State(StateKey key, std::vector<StateTransition<_StateKey, _Parameters...>> transitions);

		std::optional<StateKey> ShouldTransition(const _Parameters&... parameters) const;
	private:
		StateKey m_stateKey;
		std::vector<StateTransition<_StateKey, _Parameters...>> m_stateTransitions;
	};

	template<typename _StateKey, typename ..._Parameters>
	inline State<_StateKey, _Parameters...>::State(StateKey key, std::vector<StateTransition<_StateKey, _Parameters...>> transitions)
		: m_stateKey{key}
		, m_stateTransitions{transitions}
	{
	}

	template<typename _StateKey, typename ..._Parameters>
	inline std::optional<_StateKey> State<_StateKey, _Parameters...>::ShouldTransition(const _Parameters&... parameters) const
	{
		for (size_t transitionIndex = 0; transitionIndex < m_stateTransitions.size(); ++transitionIndex)
		{
			if (m_stateTransitions[transitionIndex].ShouldTransition(parameters...))
			{
				return std::optional<_StateKey>(m_stateTransitions[transitionIndex].GetTargetState());
			}
		}

		return std::optional<_StateKey>();
	}
}