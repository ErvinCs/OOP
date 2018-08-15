#include <iostream>
#include "../../headers/UI/AdminUI.h"

void AdminUI::run()
{
    std::cout << "Admin Mode.\n";
    bool running = true;
    while (running)
    {
        printMenu();
        int option;
        std::cout << "Enter option: ";
        std::cin >> option;
        switch(option)
        {
            case 0:
                running = false;
                break;
            case 1:
                add();
                break;
            case 2:
                remove();
                break;
            case 3:
                update();
                break;
            case 4:
                printAll();
                break;
            default:
                break;
        }
    }
}

void AdminUI::printAll()
{
    if (this->con.getSize() == 0)
        std::cout << "Empty database.\n";
    for(int i = 0; i < this->con.getSize(); i++)
    {
        std::cout << this->con.getItem(i).toString();
    }
}

void AdminUI::printMenu()
{
    std::cout << "\t0. Exit \n";
    std::cout << "\t1. Add \n";
    std::cout << "\t2. Remove \n";
    std::cout << "\t3. Update \n";
    std::cout << "\t4. Print all \n";
}

Dog readDog()
{
    std::string breed;
    std::cout << "Breed: ";
    std::cin >> breed;

    std::string name;
    std::cout << "Name: ";
    std::cin >> name;

    int age;
    std::cout << "Age: ";
    std::cin >> age;
    while (age < 0)
    {
        std::cout << "Invalid input.\nAge: ";
        std::cin >> age;
    }

    std::string photoLink;
    std::cout << "Photograph link: ";
    std::cin >> photoLink;

    return Dog(breed, name, age, photoLink);
}

void AdminUI::add()
{
    this->con.add(readDog());
    std::cout << "New Dog added.\n";
}

void AdminUI::remove()
{
    int id;
    std::cout << "Enter Dog id: ";
    std::cin >> id;
    bool result = this->con.remove(id);
    if (result)
        std::cout << "Dog removed.\n";
    else
        std::cout << "Invalid id.\n";
}

void AdminUI::update()
{
    int id;
    std::cout << "Enter Dog id: ";
    std::cin >> id;
    bool result = this->con.update(id, readDog());
    if (result)
        std::cout << "Dog updated.\n";
    else
        std::cout << "Invalid id.\n";
}

