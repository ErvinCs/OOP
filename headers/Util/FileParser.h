#ifndef LAB8_9_FILEPARSER_H
#define LAB8_9_FILEPARSER_H

#pragma once

#include <sstream>
#include <string>
#include <vector>


class FileParser
{
public:
    FileParser() = default;

    std::string strip(const std::string& str);

    std::vector<std::string> tokenize(const std::string& str, char separator);
};


#endif //LAB8_9_FILEPARSER_H
