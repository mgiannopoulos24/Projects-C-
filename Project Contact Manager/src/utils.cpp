#include "utils.h"
#include <regex>

bool isValidEmail(const std::string& email) {
    // Simple email validation using regex
    std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email, pattern);
}