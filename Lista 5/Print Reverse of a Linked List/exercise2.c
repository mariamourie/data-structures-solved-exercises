#include <stdio.h>
#include <stdlib.h>

struct Node {
	int number;
	struct Node *next;
};

typedef struct Node node;

void startList(node *list) {
	list->next = NULL;
}

int isEmpty(node *list) {
	return list->next == NULL;
}

void insertElement(node *list, int number) {
	node *newElement = (node *) malloc(sizeof(node));
	if(!newElement) {
		printf("No available memory!");
		exit(1);
	}
	newElement->number = number;
	newElement->next = NULL;
	if(isEmpty(list)) {
		list->next = newElement;
	} else {
		node *lastElement = list->next;
		while(lastElement->next != NULL)
			lastElement = lastElement->next;
		lastElement->next = newElement;
	}
}

int countElements(node *LISTA) {
	node *aux;
	int countElements = 0;
	if(LISTA->next != NULL) {
		if(aux) {
			aux = LISTA;
			while(aux->next != NULL) {
				countElements++;
				aux = aux->next;
			}
			return countElements;
		}
	} else {
		return 0;
	}
}

void printInReverseOrder(node *LISTA) {
	if(LISTA == NULL) 
		return;
	printInReverseOrder(LISTA->next);
	printf(" %d ", LISTA->number);
}

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
	
	printf("\n REVERSE ORDER \n");
	printInReverseOrder(LISTA->next);
	printf("\n\n");
	
	free(LISTA);
}
