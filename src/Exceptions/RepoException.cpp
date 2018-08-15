#include "../../headers/Exceptions/RepoException.h"

RepoException::RepoException()
{
    this->message = "";
}

RepoException::RepoException(const std::string& msg)
{
    this->message = message;
}

const char* RepoException::what()
{
    return this->message.c_str();
}