#include "exercise1.h"

void main() {
	node *LISTA = (node *) malloc(sizeof(node));
	int numberOfElements;
	
	if(!LISTA) {
		printf("No available memory!\n");
		exit(1);
	}
	
	startList(LISTA);
	
	insertElement(LISTA, 3);
	insertElement(LISTA, 42);
	insertElement(LISTA, 87);
	insertElement(LISTA, 20);
	insertElement(LISTA, 12);
	insertElement(LISTA, 34);
	insertElement(LISTA, 120);
	
	numberOfElements = countElements(LISTA);
	
	printf("Number of elements: %d \n", numberOfElements);
}
