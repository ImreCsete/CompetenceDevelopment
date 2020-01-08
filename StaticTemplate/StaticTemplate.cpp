#include <iostream>
#include <sstream>
#include <string>

#include "SQLGenerator.h"

// csak teszt
#include "Trait.h"
#include "User.h"
#include "Image.h"
using namespace StaticTemplate::Traits;
using namespace StaticTemplate::DataEntries;
// eddig

using namespace std::string_literals;

template<typename T>
class SQLGenerator
{
public:
    static std::string insert(std::initializer_list<T> items)
    {
        std::stringstream ss;

        ss << "INSERT INTO " << Trait<T>::TableName << " (";

        bool first = true;

        for (const auto& col : Trait<T>::Columns)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                ss << ", ";
            }

            ss << col;
        }

        ss << ") VALUES ";

        bool firstVal = true;

        for (const T& item : items)
        {
            if (firstVal)
            {
                firstVal = false;
            }
            else
            {
                ss << ", ";
            }

            ss << "(";

            first = true;

            for (const std::string& col : Trait<T>::Columns)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    ss << ", ";
                }

                ss << Trait<T>::getValue(item, col);
            }

            ss << ")";
        }

        ss << ";";

        return ss.str();
    }

    template<typename B>
    static std::string select(const std::string& col, const B& val)
    {
        std::stringstream ss;

        ss << "SELECT * FROM " << Trait<T>::TableName << " WHERE " << col << " = " << val << ";";

        return ss.str();
    }

    template<>
    static std::string select<std::string>(const std::string& col, const std::string& val)
    {
        std::stringstream ss;

        ss << "SELECT * FROM " << Trait<T>::TableName << " WHERE " << col << " = " << "\"" << val << "\"" << ";";

        return ss.str();
    }

    template<typename A, typename B>
    static std::string update(const std::string& colId, const A& idVal, const std::string& colName, const B& val)
    {
        std::stringstream ss;

        ss << "UPDATE " << Trait<T>::TableName << " SET " << colName << " = " << "\"" << val << "\"" << " WHERE " << colId << " = " << idVal << ";";

        return ss.str();
    }

    template<typename B>
    static std::string deletePicture(const std::string& col, const B& val)
    {
        std::stringstream ss;

        ss << "DELETE FROM " << Trait<T>::TableName << " WHERE " << col << " = " << val << ";";

        return ss.str();
    }
};


int main()
{
    std::cout << SQLGenerator<User>::insert({ User(1, "Adam", 0) }) << std::endl; // INSERT INTO user (id, name, level) VALUES (1, "Adam", 0);
    std::cout << SQLGenerator<User>::insert({ User(1, "Adam", 0), User(2, "Bela", 1) }) << std::endl; // INSERT INTO user (id, name, level) VALUES (1, "Adam", 0), (2, "Bela", 1);
    std::cout << SQLGenerator<User>::select("level", 0) << std::endl; // SELECT * FROM user WHERE level = 0;
    std::cout << SQLGenerator<User>::select("name", "Adambacsi"s) << std::endl; // SELECT * FROM user WHERE name = "Adambacsi";
    std::cout << SQLGenerator<Image>::insert({ Image(1, 1, "fESGsseg==", 1024, 768) }) << std::endl; // INSERT INTO image (id, user_id, data, width, height) VALUES (1, 1, "fESGsseg==", 1024, 768);
    std::cout << SQLGenerator<User>::update("id", 1, "name", "Karcsi") << std::endl; // UPDATE user SET name = "Karcsi" WHERE id = 1;
    std::cout << SQLGenerator<Image>::deletePicture("id", 1) << std::endl; // DELETE FROM image WHERE id = 1;

    return 0;
}
