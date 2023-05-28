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

void insert(node *list, int number) {
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

void display(node *list) {
	node *aux;
	if(!isEmpty(list)) {
		if(aux) {
			aux = list->next;
			while(aux != NULL) {
				printf(" %d ", aux->number);
				aux = aux->next;
			}
		}
	}
	free(aux);
	printf("\n\n");
}

int findHighestValue(node *list) {
	node *aux;
	int highest = list->next->number;
	
	if(!isEmpty(list)) {
		aux = list->next;
		while(aux != NULL) {
			if(aux->number > highest) {
				highest = aux->number;
			}
			aux = aux->next;
		}
	}
	return highest;
}

int findSmallestValue(node *list) {
	node *aux;
	int smallest = list->next->number;
	
	if(!isEmpty(list)){
		if(aux) {
			aux = list->next;
			while(aux != NULL) {
				if(aux->number < smallest) {
					smallest = aux->number;
				}
				aux = aux->next;
			}
		}
	}
	return smallest;
}

float averageOfNumbers(node *list) {
	node *aux;
	int sum = 0;
	int count = 0;
	
	if(!isEmpty(list)){
		if(aux) {
			aux = list->next;
			while(aux != NULL) {
				sum += aux->number;
				count++;
				aux = aux->next;
			}
		}
	}
	return sum / count;
}

void main() {
	node *list = (node*) malloc(sizeof(node));

	if(!list) {
		printf("No available memory!\n");
		exit(1);
	}
	
	startList(list);
	
	insert(list, 13);
	insert(list, 42);
	insert(list, 87);
	insert(list, 120);
	insert(list, 20);
	insert(list, 12);
	insert(list, 34);
	
	printf("Highest value: %d \n", findHighestValue(list));
	printf("Smallest value: %d \n", findSmallestValue(list));
	printf("Average: %.1f \n", averageOfNumbers(list));
}
