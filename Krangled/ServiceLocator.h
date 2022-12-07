#pragma once
#include <memory>
#include <cassert>

namespace KREN
{

	template<typename Service>
	class ServiceLocator
	{
	public:
		// We don't care about the rule of 5 because there is no data that isn't allowed to be copied in here

		virtual ~ServiceLocator() = default;
		static void ProvideService(std::shared_ptr<Service> pService);
		static Service& GetService();
	protected:
		static inline std::shared_ptr<Service> m_pService{std::make_shared<Service>()};
	};

	


	template<typename Service>
	inline void ServiceLocator<Service>::ProvideService(std::shared_ptr<Service> pService)
	{
		m_pService = pService;
	}

	template<typename Service>
	inline Service& ServiceLocator<Service>::GetService()
	{
		return *m_pService;
	}
}


