#pragma once
#include "Logger.h"
#include <memory>
#include <string>

namespace KREN
{
	class Texture;
	namespace KRInternal
	{
		std::shared_ptr<Texture> LoadImage(const std::string& path);

		template<typename T>
		inline std::shared_ptr<T> Load(const std::string& path)
		{
			Logger::LogError("Type that was tried to load at " + path + "has no supported Load function");
			return std::make_shared<T>(nullptr);
		}


		template<>
		inline std::shared_ptr<Texture> Load(const std::string& path)
		{
			std::shared_ptr<Texture> pTex = LoadImage(path);

			if (!pTex)
			{
				Logger::LogError("Failed to load texture at " + path);
			}
			return pTex;
		}
	}
}