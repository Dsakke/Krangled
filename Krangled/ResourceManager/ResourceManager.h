#pragma once
#include "..\Singleton.h"
#include <unordered_map>
#include <typeindex>
#include "Loaders.h"


namespace KREN
{
	class ResourceManager : public Singleton<ResourceManager>
	{
	public:
		template<typename T>
		std::shared_ptr<T> GetResource(const std::string& path);
	private:

		template<typename T>
		std::shared_ptr<T> LoadResource(const std::string& path) const;

		std::unordered_map<std::string, std::shared_ptr<void>>	m_Resources;
	};

	template<typename T>
	inline std::shared_ptr<T> ResourceManager::GetResource(const std::string& path)
	{
		auto it = m_Resources.find(path);
		if (it == m_Resources.end())
		{
			std::shared_ptr<T> pResource = LoadResource<T>(path);
			m_Resources.insert(std::make_pair(path, std::static_pointer_cast<void>(pResource)));
			return pResource;
		}

		return std::static_pointer_cast<T>(it->second);
	}

	template<typename T>
	inline std::shared_ptr<T> ResourceManager::LoadResource(const std::string& path) const
	{
		return KRInternal::Load<T>(path);
	}
}