#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <sstream>

class Common
{
public:
    static std::vector<std::string> split(std::string str, char delimiter);
    static std::string generatorUsers();
};

#endif // COMMON_H
