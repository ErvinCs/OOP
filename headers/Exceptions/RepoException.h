#ifndef LAB8_9_REPOEXCEPTION_H
#define LAB8_9_REPOEXCEPTION_H

#pragma once

#include <exception>
#include <string>


class RepoException : public std::exception
{
protected:
    std::string message;

public:
    RepoException();
    explicit RepoException(const std::string& msg);
    virtual const char* what();
};

#endif //LAB8_9_REPOEXCEPTION_H
