#include<sstream>

#include "Trait.h"
#include "Image.h"

using namespace StaticTemplate::DataEntries;

//std::cout << SQLGenerator<Image>::insert({ Image(1, 1, "fESGsseg==", 1024, 768) }) << std::endl; // INSERT INTO image (id, user_id, data, width, height) VALUES (1, 1, "fESGsseg==", 1024, 768);


namespace StaticTemplate
{
	namespace Traits
	{
		template<>
		const std::string Trait<Image>::TableName = "image";

		template<>
		const std::vector<std::string> Trait<Image>::Columns = { "id", "user_id", "data", "width", "height" };

		template<>
		std::string Trait<Image>::getValue(const Image& image, const std::string& column)
		{
			std::stringstream ss;

			if (column == "id")
				ss << image.getId();
			else if (column == "user_id")
				ss << image.getUserId();
			else if (column == "data")
				ss << image.getData();
			else if (column == "width")
				ss << image.getWidth();
			else if (column == "height")
				ss << image.getHeight();

			return ss.str();
		}
	}
}