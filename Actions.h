#pragma once
#include "Medication.h"
#include <string.h>
#define N 50

typedef struct
{
    Medication med;
    char type[N];
} Action;

typedef struct
{
    Action* actions;
    int length;
} AStack;

AStack newStack();
void freeStack(AStack* aStack);

Action newAction(Medication med, char type[]);
void pushAction(AStack* aStack, Action action);
Action popAction(AStack* aStack);


