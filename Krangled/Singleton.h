#pragma once
#include <memory>

namespace KREN
{
	template<class T>
	class Singleton
	{
	public:
		virtual ~Singleton() = default;

		Singleton(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton& operator=(Singleton&&) = delete;

		static T& GetInstance()
		{
			static T instance{};
			return instance;
		}

	protected:
		// protected constructor because we only want this class itself to be able to create an istance
		Singleton() = default;

	};
}