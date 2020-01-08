#pragma once

#include <string>
#include <vector>

namespace StaticTemplate
{
	namespace Traits
	{
		template<class T>
		class Trait
		{
		public:
			static const std::string TableName;
			static const std::vector<std::string> Columns;
			static std::string getValue(const T& user, const std::string& column);
		};
	}
}