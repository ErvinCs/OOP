#ifndef _DOG_H
#define _DOG_H

#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

static int idGen = 1;

class Dog
{
public:
    int age;
    std::string name;
    std::string photoLink;
private:
    std::string breed;
    int id;

public:

    /**
     * Default constructor
     */
    Dog();

    /**
     * @param breed: string
     * @param name: string
     * @param age: int
     * @param photoLink: string
     *  A link to a photograph
     */
    Dog(const std::string& breed, const std::string& name,
        const int& age, const std::string& photoLink);


    int getAge() const { return this->age; }

    void setAge(const int age) { this->age = age; }

    std::string getName() const { return this->name; }

    void setName(const std::string& name) { this->name = name; }

    std::string getPhotoLink() const { return this->photoLink;}

    void setPhotoLink(const std::string& photoLink) { this->photoLink = photoLink; }

    int getId() const { return this->id; }

    std::string getBreed() const { return this->breed; }

    /**
     * True if the 2 Dogs are the same object; false otherwise
     * @param other
     * @return: boolean
     */
    bool operator==(Dog other);

    /**
     * True if the 2 Dogs are not the same object; false otherwise
     * @param other
     * @return: boolean
     */
    bool operator!=(Dog other);

    /**
    * @return: CSV string representation: Dog{breed="", name="", age="", id=""}
    */
    std::string const toString();

    /**
     * Opens the link stored at the photolink field
     */
    void open();

};

#endif //_DOG_H