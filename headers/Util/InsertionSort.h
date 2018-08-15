#ifndef LAB5_6_INSERTIONSORT_H
#define LAB5_6_INSERTIONSORT_H

#pragma once

#include "../Repository/DynamicVector.h"
#include "Comparator.h"

/**
 * Sorts a vector, implementing the ordering of a comparator
 * @tparam T
 * @param v: DynamicVector
 * @param c: Comparator
 */
template <class T> void insertionSort(DynamicVector<T>* v, Comparator<T>& c)
{
    for(int i = 0; i < v->getSize(); i++)
    {
        for(int j = i+1; j < v->getSize(); j++)
        {
            if (c.compare(v->getItem(i), v->getItem(j)))
                std::swap(v->elements[i], v->elements[j]);
        }
    }
}


#endif //LAB5_6_INSERTIONSORT_H
