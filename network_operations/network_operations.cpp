#include "network_operations.h"

std::string get_ip(std::string const &str)
{
    std::regex exp("(\\d{1,3}(\\.\\d{1,3}){3})");

    std::smatch match;
    if (std::regex_search(str,match, exp))
        return match[1].str();
    else
        return nullptr;
}