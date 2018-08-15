#include "Actions.h"
#include <string.h>
#include <stdlib.h>

AStack newStack()
{
    AStack aStack;
    aStack.length = 0;
    return aStack;
}

void freeStack(AStack *aStack)
{
    aStack->length = 0;
    free(aStack->actions);
}

Action newAction(Medication med, char type[])
{
    Action action;
    action.med = med;

    strcpy(action.type, type);

    return action;
}

Action copyAction(Action* action)
{
    Action actionCpy = newAction(action->med, action->type);
    return actionCpy;
}

void pushAction(AStack* aStack, Action action)
{
    if (aStack->length == 0)
        aStack->actions = (Action*)malloc(sizeof(Action));
    else
        aStack->actions = (Action*)realloc(aStack->actions, (aStack->length+1)*sizeof(action));

    aStack->actions[aStack->length] = action;
    aStack->length++;
}

Action popAction(AStack* aStack)
{
    Action a = aStack->actions[aStack->length-1];
    aStack->length--;
    aStack->actions = (Action*)realloc(aStack->actions, (aStack->length)*sizeof(Action));
    return a;
}


