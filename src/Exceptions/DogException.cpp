#include "../../headers/Exceptions/DogException.h"

DogException::DogException()
{
    this->message = "";
}

DogException::DogException(const std::string& msg)
{
    this->message = msg;
}

const char* DogException::what()
{
    return message.c_str();
}