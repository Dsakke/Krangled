#pragma once
#include "Singleton.h"
#include <unordered_map>
#include <typeindex>
#include "Loaders.h"


namespace KREN
{
	class ResourceManager : public Singleton<ResourceManager>
	{
	public:
		template<typename T>
		T* GetResource(const std::string& path);
	private:

		template<typename T>
		T* LoadResource(const std::string& path) const;

		std::unordered_map<std::string, void*>	m_Resources;
	};

	template<typename T>
	inline T* ResourceManager::GetResource(const std::string& path)
	{
		auto it = m_Resources.find(path);
		if (it == m_Resources.end())
		{
			T* pResource = LoadResource<T>(path);
			m_Resources.insert(std::make_pair(path, static_cast<void*>(pResource)));
			return pResource;
		}

		return static_cast<T*>(it->second);
	}

	template<typename T>
	inline T* ResourceManager::LoadResource(const std::string& path) const
	{
		return KRInternal::Load<T>(path);
	}
}