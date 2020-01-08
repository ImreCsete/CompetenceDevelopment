#include "Image.h"

StaticTemplate::DataEntries::Image::Image(int id, int user_id, const std::string& data, int width, int height)
	: id(id), user_id(user_id), data(data), width(width), height(height)
{}

StaticTemplate::DataEntries::Image::~Image()
{}