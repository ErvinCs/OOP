#pragma once
#include "Medication.h"
#include "MedRepo.h"
#include "Actions.h"

typedef struct
{
	Array* repo;
    AStack* undo;
    AStack* redo;
    Medication* Uitems;
    int Uidx;
    Medication* Ritems;
    int Ridx;
}MedController;


MedController newMedController(Array* repo, AStack* undo, AStack* redo);
void conFreeArray(MedController* con);

int conAdd(MedController* con, Medication med);
int conRemove(MedController* con, char name[], int concentration);
int conSetItem(MedController* con, char name[], int concentration, Medication nMed);
char* ConToString(MedController* con);
Medication conGetItem(MedController* con, char name[], int concentration);

void ConNameMatch(MedController* con, char name[], Array* match);
Array ConSortByConc(MedController* con);
Array ConSortByName(MedController* con);
void ConShortSupply(MedController* con, int bound, Array* match);
