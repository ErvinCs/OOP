#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TextUI.h"
#include "MedRepo.h"
#include "MedController.h"
#include "Medication.h"
#define n 10

TextUI newTextUI(MedController* control)
{
	TextUI ui;
	ui.control = control;
	return ui;
}

void printUI()
{
	printf("\t 0.Exit \n");
	printf("\t 1.Add medication \n");
	printf("\t 2.Remove medication \n");
	printf("\t 3.Update medication \n");
	printf("\t 4.Print all \n");
	printf("\t 5.Search by name \n");
	printf("\t 6.Sort by name \n");
	printf("\t 7.Sort by concentration \n");
	printf("\t 8.Check supply \n");
	printf("\t 9.Undo \n");
	printf("\t 10.Redo \n");
}

int readCommand()
{
	int command;
	printf("Enter command: ");
	scanf(" %d", &command);

	while (command < 0 || command > n)
	{
		printf("Enter command: ");
		scanf(" %d", &command);
	}

	return command;
}

Medication readMed()
{
	Medication med;

	printf("Name: ");
	scanf(" %s", med.name);

	printf("Concentration:");
	scanf(" %d", &med.concentration);

	printf("Quantity: ");
	scanf(" %d", &med.quantity);

	printf("Price: ");
	scanf(" %d", &med.price);

	return med;
}

void addMed(TextUI* ui)
{
	int found = conAdd(ui->control, readMed());
	if (found == 0)
        printf("New medication added.\n");
	else
        printf("Medication exists. Updated.\n");
}

void remMed(TextUI* ui)
{

	char name[50];
	printf("Name of medicine: ");
	scanf(" %s", name);

	int concentration;
	printf("Concentration of medicine: ");
	scanf(" %d", &concentration);

	int found = conRemove(ui->control, name, concentration);
	if (found == 1)
        printf("Medication removed.\n");
    else
        printf("Could not find medication.\n");
}

void updateMed(TextUI *ui)
{
	char name[50];
	printf("Name of medicine: ");
	scanf(" %s", name);

	int concentration;
	printf("Concentration of medicine: ");
	scanf(" %d", &concentration);

	Medication nMed = readMed();
	int found = conSetItem(ui->control, name, concentration, nMed);
	if (found == 1)
        printf("Medication updated.\n");
    else
        printf("Could not find medication.\n");
}

void printMed(TextUI* ui)
{
	printf("%s", ConToString(ui->control));
}

void printNameMatch(TextUI* ui)
{
	char name[50];
	printf("Name to match: ");
	scanf(" %s", name);
	Array arr = newArray(0);
	ConNameMatch(ui->control, name, &arr);
	if (arr.size == 0)
        printf("No names match.\n");
    else
        printf("%s", ArrToString(&arr));
	freeArray(&arr);
}

void printShortSupply(TextUI* ui)
{
	int supply;
	printf("Supply bound: ");
	scanf("%d", &supply);
	Array arr = newArray(0);
	ConShortSupply(ui->control, supply, &arr);
	if (arr.size == 0)
        printf("Nothing to show.\n");
    else
        printf("%s", ArrToString(&arr));
	freeArray(&arr);
}

void printSortedByConc(TextUI* ui)
{
    Array arr = ConSortByConc(ui->control);
	printf("%s", ArrToString(&arr));
}

void printSortedByName(TextUI* ui)
{
    Array arr = ConSortByName(ui->control);
	printf("%s", ArrToString(&arr));
}

void run(TextUI* ui)
{
	int loop = 1;
	while (loop)
	{
		printUI();
		int command = readCommand();
		int u, r;
		switch (command)
		{
		case 0:
			loop = 0;
			break;
		case 1:
			addMed(ui);
			break;
		case 2:
			remMed(ui);
			break;
		case 3:
			updateMed(ui);
			break;
		case 4:
			printMed(ui);
			break;
		case 5:
			printNameMatch(ui);
			break;
		case 6:
			printSortedByName(ui);
			break;
		case 7:
			printSortedByConc(ui);
			break;
		case 8:
			printShortSupply(ui);
			break;
        case 9:
            undo(ui->control);
            printf("Undone.\n");
            break;
        case 10:
            redo(ui->control);
            printf("Redone.\n");
            break;
		}
		if (loop == 0)
			break;
	}
	conFreeArrays(ui->control);
}
