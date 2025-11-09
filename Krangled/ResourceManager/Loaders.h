#pragma once
#include "..\Logger\Logger.h"
#include <memory>
#include <string>

namespace KREN
{
	class Texture;
	class Audio;
	namespace KRInternal
	{
		class Loader
		{
		public:
			static std::shared_ptr<Texture> LoadImage(const std::string& path);
			static std::shared_ptr<Audio> LoadAudio(const std::string& path);

			template<typename T>
			inline static std::shared_ptr<T> Load(const std::string& path)
			{
				Logger::LogError("Type that was tried to load at " + path + "has no supported Load function");
				return std::make_shared<T>(nullptr);
			}

			template<>
			inline static  std::shared_ptr<Texture> Load(const std::string& path)
			{
				std::shared_ptr<Texture> pTex = LoadImage(path);

				if (!pTex)
				{
					Logger::LogError("Failed to load texture at " + path);
				}
				return pTex;
			}

			template<>
			inline static std::shared_ptr<Audio> Load(const std::string& path) 
			{
				std::shared_ptr<Audio> pAudio = LoadAudio(path);
			
				if (!pAudio)
				{
					Logger::LogError("Failed to load audio at " + path);
				}

				return pAudio;
			}

		private:
			static std::shared_ptr<Audio> LoadWavToAudio(std::fstream& stream);

		};
	}
}