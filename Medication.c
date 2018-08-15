#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Medication.h"


Medication newMed(char name[], int concentration, int quantity, int price)
{
	Medication med;
	strcpy(med.name, name);
	med.concentration = concentration;
	med.quantity = quantity;
	med.price = price;
	return med;
}

Medication copyMed(Medication* med)
{
    Medication medCpy = newMed(med->name, med->concentration, med->quantity, med->price);
    return medCpy;
}

char* getName(Medication med)
{
	return med.name;
}

int getConcentration(Medication med)
{
	return med.concentration;
}

int getQuantity(Medication med)
{
	return med.quantity;
}

int getPrice(Medication med)
{
	return med.price;
}

void setName(Medication* med, char name[])
{
	strcpy(med->name, name);
}

void setConcentration(Medication* med, int concentration)
{
	med->concentration = concentration;
}

void setQuantity(Medication* med, int quantity)
{
	med->quantity = quantity;
}

void setPrice(Medication* med, int price)
{
	med->price = price;
}

char* toString(Medication* med)
{
	char buffer[100];
	char* string = (char*)malloc(sizeof(char)*200);
	strcpy(string, "");
	strcat(string, "Medication{name=");
	strcat(string, med->name);
	strcat(string, ", concentration=");
	itoa(med->concentration, buffer, 10);
	strcat(string, buffer);
	strcpy(buffer, "");
	strcat(string, ", quantity=");
	itoa(med->quantity, buffer, 10);
	strcat(string, buffer);
	strcpy(buffer, "");
	strcat(string, ", price=");
	itoa(med->price, buffer, 10);
	strcat(string, buffer);
	strcpy(buffer, "");
	strcat(string, "}\n\0");

    return string;
}
