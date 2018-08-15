#include "MedController.h"

typedef struct
{
	MedController* control;
}TextUI;

/**
*   Returns a new TextUI.
*   @param control - MedController*
*/
TextUI newTextUI(MedController* control);
/**
*   Run a menu-based UI.
*/
void run(TextUI* ui);

