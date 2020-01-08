#include "SQLGenerator.h"

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
};