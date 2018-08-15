#ifndef _DATABASE_H
#define _DATABASE_H

#pragma once

#include "DynamicVector.h"

template<typename T> class Database
{
private:
    DynamicVector<T> repo;
    int current = 0;
public:

    /**
     * Default constructor
     */
    Database() {}

    /**
    * Copy constructor
    * @param other: Database<T>
    */
    Database(const Database<T>& other)
    {
        this->repo = other.repo;
        this->current = 0;
    }

    /**
     * @return: all the elements of the repo
     */
    T* getAll() const
    {
        return repo.elements;
    }

    /**
     * @param index: the position of an item in the array
     * @return: the item at index
     */
    T getItem(const int index) const
    {
        return repo.getItem(index);
    }

    /**
     * Adds an item to the repo
     * @tparam T
     * @param item: T
     */
    void add(const T& item)
    {
        return repo.add(item);
    }

    /**
      * Removes an item from the repo
      * @param id
      * @return: boolean
      *  True if an item was successfully removed; false otherwise
      */
    bool remove(const int id) {
        return repo.remove(id);
    }

    /**
     * Updates the fields of an item in the repo
     * @tparam T
     * @param id: id of the item to update
     * @param elem: T
     * @return: boolean
     *  True if an item was successfully updated; false otherwise
     */
    bool update(const int id, const T elem)
    {
        return repo.update(id, elem);
    }

    /**
    * @return: int: the zie of the repository
    */
    int getSize()   //const
    {
        return repo.getSize();
    }

    std::string toString()
    {
        std::string output;
        for(int i = 0; i < this->repo.getSize(); i++)
        {
            output += this->getItem(i).toString();
        }
        return output;
    }

    /**
     * Deprecated
     * @param breed: string
     * @param age: int
     * @return: a new Database<T> containing the items that match the parameters' values
     */
    Database<T> newBreedAge(const std::string& breed, const int& age)
    {
        if (breed == "")
            return *this;
        Database<T> db = Database<T>();
        for(int i = 0; i < this->getSize(); i++)
        {
            if (this->repo.getItem(i).getBreed() == breed && this->repo.getItem(i).getAge() < age)
                db.add(this->repo.getItem(i));
        }
        return db;
    }

    /**
     * Iterator
     * @return: the current item in the repo
     */
    T getCurrent()
    {
        if (this->current == this->getSize())
            this->current = 0;
        if (this->getSize() > 0)
            return this->repo.getItem(current);

        return T {};
    }

    /**
     * Iterator
     * @return: the next item in the repo
     */
    bool next()
    {
        if (this->getSize() == 0)
            return false;
        this->current += 1;
        return true;
    }

    /**
     * Iterator
     * @return: the previous item in the repo
     */
    bool previous()
    {
        if (this->getSize() == 0)
            return false;
        this->current -= 1;
        return true;
    }

};

#endif //_DATABASE_H