#include "StringUtilities.h"
#include <algorithm>
#include <cctype>


bool LowerCaseCompare(char lhs, char rhs);

bool KREN::StringUtilities::CompareIgnoreCase(const std::string& lhs, const std::string& rhs)
{
    return lhs.length() == rhs.length() && std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin(), LowerCaseCompare);
}

bool LowerCaseCompare(char lhs, char rhs)
{
    return std::tolower(lhs) == std::tolower(rhs);
}
