#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MedRepo.h"
#define N 50

Array newArray(int size)
{
	Array arr;
	arr.size = 0;
	return arr;
}

void freeArray(Array* arr)
{
	arr->size = 0;
	free(arr->array);
}

void copyArray(Array* original, Array* copy)
{
    int i;
    for(i = 0; i < original->size; i++)
        add(copy, original->array[i]);
}

int add(Array* arr, Medication med)
{
	int i;
	int found = 0;
	for (i = 0; i < arr->size; i++)
	{
		if ((strcmp(med.name, arr->array[i].name) == 0) && (med.concentration == arr->array[i].concentration))
		{
			arr->array[i].quantity += med.quantity;
			found = 1;
		}
	}
	if (found == 0)
	{
	    if (arr->size == 0)
            arr->array = (Medication*)malloc(sizeof(Medication));
        else
            arr->array = (Medication*)realloc(arr->array, (arr->size+1)*sizeof(Medication));
		arr->array[arr->size] = med;
        arr->size++;
	}
	return found;
}

int rem(Array* arr, char name[], double concentration, Medication* med)
{
	int i;
	int found = 0;
	for (i = 0; i < arr->size && found == 0; i++)
	{
		if ((strcmp(arr->array[i].name, name) == 0) && (arr->array[i].concentration == concentration))
		{
			found = 1;
			*med = newMed(arr->array[i].name, arr->array[i].concentration, arr->array[i].quantity, arr->array[i].price);
			int j;
			arr->size--;
			for (j = i; j < arr->size; j++)
				arr->array[j] = arr->array[j + 1];
			arr->array = (Medication*)realloc(arr->array, (arr->size) * sizeof(Medication));
		}
	}
	return found;
}

int setItem(Array* arr, char name[], double concentration, Medication nMed, Medication* oMed)
{
	int i;
	int found = 0;
	for (i = 0; i < arr->size && found == 0; i++)
	{
		if (strcmp(arr->array[i].name, name) == 0 && (arr->array[i].concentration == concentration))
		{
			found = 1;
			*oMed = newMed(arr->array[i].name, arr->array[i].concentration, arr->array[i].quantity, arr->array[i].price);
			arr->array[i] = nMed;
		}
	}
	return found;
}

Medication getItem(Array* arr, char name[], double concentration)
{
	int i;
	int found = 0;
	for (i = 0; i < arr->size && found == 0; i++)
	{
		if (strcmp(arr->array[i].name, name) == 0 && (arr->array[i].concentration == concentration))
		{
			found = 1;
			return arr->array[i];
		}
	}
}

char* ArrToString(Array* med)
{
	char* string = (char*)calloc(med->size,sizeof(med->array[0]));
	strcpy(string, toString(&med->array[0]));

	int i;
	for (i = 1; i < med->size; i++)
        strcat(string, toString(&med->array[i]));

    return string;
}

int strMatch(char* c1, char* c2)
{
	if (strlen(c1) < strlen(c2))
	{
		char aux[N];
		strcpy(aux, "");
		strcpy(aux, c1);
		strcpy(c1, c2);
		strcpy(c2, aux);
	}
	if (strstr(c1, c2) != NULL)
		return 1;
	return 0;

}

void nameMatch(Array* arr, char* name, Array* match)
{
	int i;
	for (i = 0; i < arr->size; i++)
		if (strMatch(arr->array[i].name, name))
		    add(match, arr->array[i]);
}


void shortSupply(Array* arr, int bound, Array* match)
{
	int i;
	for (i = 0; i < arr->size; i++)
		if (arr->array[i].quantity > bound)
            add(match, arr->array[i]);
}

Array sortByConc(Array* arr)
{
	Array sorted = newArray(0);
	copyArray(arr, &sorted);

	int i;
	for (i = 0; i < sorted.size; i++)
	{
		int j;
		for (j = i + 1; j < sorted.size; j++)
		{
			if (sorted.array[i].concentration >= sorted.array[j].concentration)
			{
				Medication aux = sorted.array[i];
				sorted.array[i] = sorted.array[j];
				sorted.array[j] = aux;
			}
		}
	}

	return sorted;
}

Array sortByName(Array* arr)
{
	Array sorted = newArray(0);
	copyArray(arr, &sorted);

	int i;
	for (i = 0; i < sorted.size; i++)
	{
		int j;
		for (j = i + 1; j < sorted.size; j++)
		{
			if (strcmp(sorted.array[i].name, sorted.array[j].name) < 0)
			{
				Medication aux = sorted.array[i];
				sorted.array[i] = sorted.array[j];
				sorted.array[j] = aux;
			}
		}
	}

	return sorted;
}

Array sortByPrice(Array* arr)
{
	Array sorted = newArray(0);
	copyArray(arr, &sorted);

	int i;
	for (i = 0; i < sorted.size; i++)
	{
		int j;
		for (j = i + 1; j < sorted.size; j++)
		{
			if (sorted.array[i].price >= sorted.array[j].price)
			{
				Medication aux = sorted.array[i];
				sorted.array[i] = sorted.array[j];
				sorted.array[j] = aux;
			}
		}
	}

	return sorted;
}




