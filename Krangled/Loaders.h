#pragma once
#include "Logger.h"
#include "Texture.h"
#include <memory>
#include <string>

namespace KREN
{
	namespace KRInternal
	{
		Texture* LoadImage(const std::string& path);

		template<typename T>
		inline T* Load(const std::string& path)
		{
			Logger::LogError("Type that was tried to load at " + path + "has no supported Load function");
			return std::make_shared<T>(nullptr);
		}


		template<>
		inline Texture* Load(const std::string& path)
		{
			Texture* pTex = LoadImage(path);

			if (!pTex)
			{
				Logger::LogError("Failed to load texture at " + path);
			}
			return pTex;
		}


	}
}