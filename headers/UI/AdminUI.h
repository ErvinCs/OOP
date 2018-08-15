#ifndef _ADMINUI_H
#define _ADMINUI_H

#pragma once

#include "UI.h"
#include <cstring>
#include "../../headers/Controller/Controller.h"

class AdminUI: public UI<Dog>
{
public:
    Controller<Dog>& con;
public:
    explicit AdminUI(Controller<Dog>& c) : con(c) {}

    //Dog readDog();

    void add();

    void remove();

    void update();

    void printAll();

    void printMenu() override;

    void run() override;
};

#endif //_ADMINUI_H