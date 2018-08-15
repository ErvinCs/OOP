#include <stdio.h>
#include <stdlib.h>
#include "TextUI.h"
#include "MedController.h"
#include "MedRepo.h"
#include "Medication.h"
#include "Actions.h"

Array setUpArray()
{
    Array arr = newArray(0);

    Medication med1 = newMed("new", 2, 20, 2);
    Medication med2 = newMed("new2", 1, 10, 1);
    Medication med3 = newMed("new3", 3, 30, 3);
    Medication med4 = newMed("med1", 1, 20, 3);
    Medication med5 = newMed("med2", 4, 5, 6);
    Medication med6 = newMed("med3", 2, 30, 100);
    Medication med7 = newMed("something1", 25, 200, 2);
    Medication med8 = newMed("something2", 1, 1, 1);
    Medication med9 = newMed("Ibuprofen", 2, 2, 2);
    Medication med10 = newMed("Opium", 3, 4, 5);

    add(&arr, med1);
    add(&arr, med2);
    add(&arr, med3);
    add(&arr, med4);
    add(&arr, med5);
    add(&arr, med6);
    add(&arr, med7);
    add(&arr, med8);
    add(&arr, med9);
    add(&arr, med10);

    return arr;
}

int main()
{
    //printf("Array\n");
    Array arr = setUpArray();
    printf("%s\n", ArrToString(&arr));
    //printf("ExecutionStack\n");
    AStack undo = newStack();
    AStack redo = newStack();
    //printf("Controller\n");
    MedController con = newMedController(&arr, &undo, &redo);
    //printf("UI\n");
    TextUI ui = newTextUI(&con);
    //printf("Run\n");
	run(&ui);

    return 0;
}
