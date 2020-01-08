#pragma once

#include <string>

//std::cout << SQLGenerator<Image>::insert({ Image(1, 1, "fESGsseg==", 1024, 768) }) << std::endl; // INSERT INTO image (id, user_id, data, width, height) VALUES (1, 1, "fESGsseg==", 1024, 768);

namespace StaticTemplate
{
	namespace DataEntries
	{
		class Image
		{
			int id;
			int user_id;
			std::string data;
			int width;
			int height;

		public:
			Image(int id, int user_id, const std::string& data, int width, int height);
			virtual ~Image();

			int getId() const { return id; }
			void setId(int id);

			int getUserId() const { return user_id; }
			void setUserId(int id);

			std::string getData() const { return data; }
			void setData(const std::string& data);

			int getWidth() const { return width; }
			void setWidth(int width);

			int getHeight() const { return height; }
			void setHeight(int height);
		};
	}
}