#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#pragma once

#include "../Repository/Database.h"
#include "../Domain/Dog.h"

template<typename T> class Controller
{
private:
    Database<T> repo;
public:

    Controller(const Database<T>& r) : repo(r) {}

    T* getAll() const
    {
        return repo.getAll();
    }

    T getItem(const int index) const
    {
        return repo.getItem(index);
    }

    int getSize()
    {
        return repo.getSize();
    }

    void add(const T& dog)
    {
        this->repo.add(dog);
    }

    bool remove(const int id)
    {
        return this->repo.remove(id);
    }

    bool update(const int id, const T elem)
    {
        return this->repo.update(id, elem);
    }

//    Database<T> newBreedAge(const std::string& breed, const int& age)
//    {
//        return this->repo.newBreedAge(breed, age);
//    }

    T getCurrent()
    {
        return this->repo.getCurrent();
    }

    bool next()
    {
        return this->repo.next();
    }

    bool previous()
    {
        return this->repo.previous();
    }


};

#endif //_CONTROLLER_H