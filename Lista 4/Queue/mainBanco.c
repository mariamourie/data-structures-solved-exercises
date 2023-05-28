#include "banco.h"

void main() {
	queue *queue = malloc(sizeof(queue));
	TClient client;
	int opc;
	
	startQueue(queue);

	while(opc != 5) {
		opc = getOpcao();
		menu(opc, queue);
	}
}
