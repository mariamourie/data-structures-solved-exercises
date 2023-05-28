#ifndef __EXERCISE1__
#define __EXERCISE1__
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

void displayList(node *LISTA) {
	node *aux;
	if(!isEmpty(LISTA)) {
		aux = LISTA->next;
		while(aux != NULL) {
			printf(" %d ", aux->number);
			aux = aux->next;
		}
	} else {
		printf("List is empty!\n");
	}
	printf("\n\n");
	free(aux);
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

#endif
