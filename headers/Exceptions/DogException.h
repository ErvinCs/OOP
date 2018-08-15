#ifndef LAB8_9_DOGEXCEPTION_H
#define LAB8_9_DOGEXCEPTION_H

#pragma once

#include <exception>
#include <string>

class DogException: public std::exception
{
protected:
    std::string message;

public:
    DogException();
    explicit DogException(const std::string& msg);
    virtual const char* what();
};

#endif //LAB8_9_DOGEXCEPTION_H
