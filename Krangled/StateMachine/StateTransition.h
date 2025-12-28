#pragma once
#include <functional>

namespace KREN
{
	template<typename _StateKey, typename... _Parameters>
	class StateTransition
	{
	public:
		typedef _StateKey StateKey;

		StateTransition(const StateKey& targetState, const std::function<bool(_Parameters...)>& predicate);

		bool ShouldTransition(const _Parameters&... parameters) const;
		StateKey GetTargetState();

	private:
		StateKey m_TargetState;
		std::function<bool(_Parameters...)> m_Predicate;
	};

	template<typename _StateKey, typename ..._Parameters>
	inline StateTransition<_StateKey, _Parameters...>::StateTransition(const StateKey& targetState, const std::function<bool(_Parameters...)>& predicate)
		: m_TargetState{targetState}
		, m_Predicate{predicate}
	{
	}

    template<typename _StateKey, typename ..._Parameters>
    inline bool StateTransition<_StateKey, _Parameters...>::ShouldTransition(const _Parameters&... parameters) const
    {
        return m_Predicate(parameters...);    
    }

	template<typename _StateKey, typename ..._Parameters>
	inline _StateKey StateTransition<_StateKey, _Parameters...>::GetTargetState()
	{
		return m_TargetState;
	}
}