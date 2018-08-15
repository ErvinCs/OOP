#ifndef LAB5_6_COMPARATOR_H
#define LAB5_6_COMPARATOR_H

#pragma once

#include <cstring>

/**
 * Declares a compare function taking 2 parameters
 * @tparam T
 */
template<typename T> class Comparator
{
public:
    /**
     * Compares 2 items
     * @param item1: T
     * @param item2: T
     * @return: boolean
     */
    virtual bool compare(T item1, T item2) = 0;
};

#endif //LAB5_6_COMPARATOR_H
