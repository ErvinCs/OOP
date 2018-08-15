#ifndef _USERUI_H
#define _USERUI_H

#pragma once

#include "UI.h"
#include <cstring>
#include "../../headers/Repository/Database.h"

class UserUI: public UI<Dog>
{
private:
    Controller<Dog>& con;
    Database<Dog> dogDb = Database<Dog>();
    bool filterOn = false;
public:
    std::string breed = "";
    int age = -1;

    explicit UserUI(Controller<Dog>& c) : con(c) {}
    
    void next();

    bool adopt();

    void filterBreedAge(std::string& breed, int& age);

    void printAdoptionList();

    void printMenu() override;

    void run() override;
};


#endif //_USERUI_H