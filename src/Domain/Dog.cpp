#include "../../headers/Domain/Dog.h"
#include <windows.h>
#include <shellapi.h>

Dog::Dog()
{
    this->breed = "";
    this->name = "";
    this->age = -1;
    this->photoLink = "";
    this->id = idGen;
    idGen += 1;
}

Dog::Dog(const std::string& breed, const std::string& name, const int& age, const std::string& photoLink)
{
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->photoLink = photoLink;
    this->id = idGen;
    idGen += 1;
}

bool Dog::operator==(Dog other)
{
    return (this->breed == other.breed && this->name == other.name &&
            this->age == other.age && this->photoLink == other.photoLink && this->id == other.id);
}

bool Dog::operator!=(Dog other)
{

    return !(this->breed == other.breed && this->name == other.name &&
            this->age == other.age && this->photoLink == other.photoLink && this->id == other.id);
}

const std::string Dog::toString()
{
    std::string ageStr = std::to_string(this->age);
    std::string idStr = std::to_string(this->id);

    std::string dogStr = "Dog{breed=" + breed + ", name=" + name
                         + ", age=" + ageStr + ", id=" + idStr +"}\n";
    return dogStr;
}

void Dog::open()
{
    ShellExecuteA(nullptr, nullptr, "firefox.exe", this->photoLink.c_str(), nullptr, SW_SHOWMAXIMIZED);
}

