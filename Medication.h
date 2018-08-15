#pragma once

typedef struct
{
	char name[50];
	int concentration;
	int quantity;
	int price;

} Medication;

/**
*   Returns a new Medication.
*   @param name - char array
*   @param concentration - integer number
*   @param quantity - integer number
*   @param price - integer number
*/
Medication newMed(char name[], int concentration, int quantity, int price);
/**
*   Copies a Medication object and returns a new one.
*   @param med - medication pointer to copy
*/
Medication copyMed(Medication* med);

char* getName(Medication med);
int getConcentration(Medication med);
int getQuantity(Medication med);
int getPrice(Medication med);

void setName(Medication* med, char name[]);
void setConcentration(Medication* med, int concentration);
void setQuantity(Medication* med, int quantity);
void setPrice(Medication* med, int price);

/**
*   Returns a char* representation of a Medication
*   @param med - pointer to the Medication to copy
*/
char* toString(Medication* med);
