#include "banco.h"

void main() {
	node *list = (node *) malloc(sizeof(node));
	int opc;
	
	if(!list) {
		printf("No available memory!\n");
		exit(1);
	}
	
	startList(list);
	
	while(opc != 5) {
		opc = getOption();
		menu(opc, list);
	}
	
}
