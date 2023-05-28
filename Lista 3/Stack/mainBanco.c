#include "banco.h"

void main() {
	stack * stack = malloc(sizeof(stack));
	TClient client;
	int opc;
	
	startStack(stack);
	
	while(opc != 5) {
		opc = getOpcao();
		menu(opc, stack);
	}
}
