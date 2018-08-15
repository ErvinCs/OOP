#include <stdio.h>
#include <stdlib.h>
#include "MedRepo.h"
#include "MedController.h"
#include "Actions.h"

MedController newMedController(Array* repo, AStack* undo, AStack* redo)
{
	MedController con;
	con.repo = repo;
	con.undo = undo;
	con.redo = redo;
	con.Uitems = (Medication*)malloc(sizeof(Medication));
	con.Ritems = (Medication*)malloc(sizeof(Medication));
	con.Uidx = 0;
	con.Ridx = 0;
	return con;
}

void conFreeArrays(MedController* con)
{
	freeArray(con->repo);
	freeStack(con->undo);
	freeStack(con->redo);
	free(con->Uitems);
	free(con->Ritems);
}

int conAdd(MedController* con, Medication med)
{
    int result = add(con->repo, med);
    if (result == 1 || result == 0)
    {
        Action action = newAction(med, "add");
        pushAction(con->undo, action);
    }
	return result;
}

int conRemove(MedController* con, char name[], int concentration)
{
    Medication removed;
    int result = rem(con->repo, name, concentration, &removed);
    //printf(toString(&removed));
    if (result == 1)
    {
        Action action = newAction(removed, "remove");
        pushAction(con->undo, action);
    }
    return result;
}

int conSetItem(MedController* con, char name[], int concentration, Medication nMed)
{
    Medication old;
	int result = setItem(con->repo, name, concentration, nMed, &old);
    //printf(toString(&old));
	if (result == 1)
    {
        Action action = newAction(old, "update");
        pushAction(con->undo, action);

        con->Uitems[con->Uidx] = newMed(nMed.name, nMed.concentration, nMed.quantity, nMed.price);
        con->Uidx++;
        con->Uitems = (Medication*)realloc(con->Uitems, (con->Uidx+1) * sizeof(Medication));
    }
	return result;
}

Medication conGetItem(MedController* con, char name[], int concentration)
{
	return getItem(con->repo, name, concentration);
}
char* ConToString(MedController* con)
{
	return ArrToString(con->repo);
}
void ConNameMatch(MedController* con, char name[], Array* match)
{
	nameMatch(con->repo, name, match);
}
Array ConSortByConc(MedController* con)
{
	return sortByConc(con->repo);
}
Array ConSortByName(MedController* con)
{
	return sortByName(con->repo);
}
void ConShortSupply(MedController* con, int bound, Array* match)
{
	shortSupply(con->repo, bound, match);
}

int undo(MedController* con)
{
    if (con->undo->length == 0)
        return 0;


    Action a = popAction(con->undo);
    if (strcmp(a.type, "add") == 0)
    {
        Medication med = a.med;
        Action newAc = newAction(med, "remove");
        pushAction(con->redo, newAc);
        return rem(con->repo, med.name, med.concentration, &med);
    }
    if (strcmp(a.type, "remove") == 0)
    {
        Medication med = a.med;
        Action newAc = newAction(med, "add");
        pushAction(con->redo, newAc);
        return add(con->repo, med);
    }
    if (strcmp(a.type, "update") == 0)
    {
        Medication med = a.med;
        con->Uidx--;
        Medication nMed = con->Uitems[con->Uidx];

        int res = setItem(con->repo, nMed.name, nMed.concentration, med, &nMed);
        con->Ritems[con->Ridx] = newMed(med.name, med.concentration, med.quantity, med.price);
        con->Ridx++;
        con->Ritems = (Medication*)realloc(con->Ritems, (con->Ridx+1) * sizeof(Medication));

        Action newAc = newAction(nMed, "update");
        pushAction(con->redo, newAc);

        return res;
    }
    return 0;
}

int redo(MedController* con)
{
    if (con->redo->length == 0)
        return 0;

    Action a = popAction(con->redo);
    if (strcmp(a.type, "add") == 0)
    {
        Medication med = a.med;
        Action newAc = newAction(med, "remove");
        pushAction(con->undo, newAc);
        return rem(con->repo, med.name, med.concentration, &med);
    }
    if (strcmp(a.type, "remove") == 0)
    {
        Medication med = a.med;
        Action newAc = newAction(med, "add");
        pushAction(con->undo, newAc);
        return add(con->repo, med);
    }
    if (strcmp(a.type, "update") == 0)
    {
        Medication med = a.med;
        con->Ridx--;
        Medication nMed = con->Ritems[con->Ridx];

        int res = setItem(con->repo, nMed.name, nMed.concentration, med, &nMed);
        con->Uitems[con->Uidx] = newMed(nMed.name, nMed.concentration, nMed.quantity, nMed.price);
        con->Uidx++;
        con->Uitems = (Medication*)realloc(con->Uitems, (con->Uidx+1) * sizeof(Medication));

        Action newAc = newAction(med, "update");
        pushAction(con->undo, newAc);

        return res;
    }
    return 0;
}
