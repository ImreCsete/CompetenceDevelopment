#include "User.h"

StaticTemplate::DataEntries::User::User(int id, const std::string& name, int level)
	: id(id), name(name), level(level)
{}

StaticTemplate::DataEntries::User::~User()
{}