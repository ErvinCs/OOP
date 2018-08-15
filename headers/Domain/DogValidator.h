#ifndef LAB8_9_DOGVALIDATOR_H
#define LAB8_9_DOGVALIDATOR_H

#pragma once

#include <string>
#include "../../headers/Domain/Dog.h"

class DogValidator
{
    bool validate(const std::string& breed, const std::string& name, const int& age, const std::string& photoLink);
};

#endif //LAB8_9_DOGVALIDATOR_H
