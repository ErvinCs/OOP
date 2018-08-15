#pragma once
#include "Medication.h"


typedef struct
{
	Medication* array;
	int size;
} Array;

/**
*   Returns a new empty Array.
*   @param size = 0
*/
Array newArray(int size);
/**
*   Frees an Array from the memory.
*   @param arr - pointer to the Array
*/
void freeArray(Array* arr);
/**
*   Copies an Array.
*   @param original - object to copy
*   @param copy - return the copy of the Array
*/
void copyArray(Array* original, Array* copy);

/**
*   Adds a new Medication to the Array.
*   @param arr - array to add to
*/
int add(Array* arr, Medication med);
/**
*   Removes a Medication with the given parameters from the Array.
*   @param arr - array to remove from
*   @param name[] - of the Medication to remove
*   @param concentration - of the Medication to remove
*/
int rem(Array* arr, char name[], double concentration, Medication* med);
/**
*   Updates an item in the Array.
*   @param arr - array to update
*   @param name[] - of the Medication to update
*   @param concentration - of the Medication to update
*   @param nMed - value to assign to the Medication
*/
int setItem(Array* arr, char name[], double concentration, Medication nMed, Medication* oMed);
/**
*   Finds and returns a Medication
*   @param arr - array to update
*   @param name[] - of the Medication to get
*   @param concentration - of the Medication to get
*/
Medication getItem(Array* arr, char name[], double concentration);
/**
*   Returns a string representation of an Array.
*   @param arr
*/
char* ArrToString(Array* arr);

/**
*   Returns a new Array with the Medications that match.
*   @param arr
*   @param name[] - to match
*   @param match - output Array
*/
void nameMatch(Array* arr, char name[], Array* match);
/**
*   Returns a new Array, sorted by concentration.
*   @param arr - to sort
*/
Array sortByConc(Array* arr);
/**
*   Returns a new Array sorted by name.
*   @param arr - to sort
*/
Array sortByName(Array* arr);
/**
*   Returns a new Array, containing the Medications with a quantity lower than a value.
*   @param arr
*   @param bound
*   @param match - output Array
*/
void shortSupply(Array* arr, int bound, Array* match);

