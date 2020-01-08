#pragma once

#include <string>

namespace StaticTemplate
{
	namespace DataEntries
	{
		class User
		{
			int id;
			std::string name;
			int level;

		public:
			User(int id, const std::string& name, int level);
			virtual ~User();

			int getId() const { return id; }
			void setId(int id);

			std::string getName() const { return name; }
			void setName(const std::string& name);

			int getLevel() const { return level; }
			void setLevel(int level);
		};
	}
}
