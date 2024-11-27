GUI: SpendFlow.c GUI.c GUI.h GUI_inputs.c GUI_inputs.h users.c
	gcc SpendFlow.c -o SpendFlow GUI.c GUI_inputs.c users.c budget_calculation.c transation_helpers.c sortHistory.c addtransaction.c

GUI2: SpendFlow.c GUI.c GUI.h GUI_inputs.c GUI_inputs.h
	gcc SpendFlow.c -o SpendFlow GUI.c GUI_inputs.c 