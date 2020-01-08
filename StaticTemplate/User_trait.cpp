#include<sstream>

#include "Trait.h"
#include "User.h"

using namespace StaticTemplate::DataEntries;

namespace StaticTemplate
{
	namespace Traits
	{
		template<>
		const std::string Trait<User>::TableName = "user";

		template<>
		const std::vector<std::string> Trait<User>::Columns = {"id", "name", "level"};

		template<>
		std::string Trait<User>::getValue(const User& user, const std::string& column)
		{
			std::stringstream ss;

			if (column == "id")
				ss << user.getId();
			else if (column == "name")
				ss << user.getName();
			else if (column == "level")
				ss << user.getLevel();

			return ss.str();
		}
	}
}