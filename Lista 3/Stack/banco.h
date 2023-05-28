#ifndef __BANCO__
#define __BANCO__
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int cpf;
	char name[50];
	char address[50];
	char tel[10];
	float balance;
} TClient;

struct Node {
	TClient client;
	struct Node *next;
};

typedef struct Node node;

struct Stack {
	int count;
	node * top;
};

typedef struct Stack stack;

void startStack(stack *stack) {
	stack->count = 0;
	stack->top = NULL;
}

int isEmpty(stack *stack) {
	return stack->top == NULL;
}

node * verifyClient(stack *stack, int cpf) {
	node *aux;
	if(!isEmpty(stack)) {
		aux = stack->top;
		while(aux != NULL) {
			if(aux->client.cpf == cpf) {
				return aux;
			}
			aux = aux->next;
		}
		return NULL;
	}
}

void withdrawValue(stack *stack, int cpf, float value) {
	node *tmp = verifyClient(stack, cpf);
	if(tmp != NULL) {
		if(tmp->client.balance < value) {
			printf("Insuficient funds!\n");
		} else {
			tmp->client.balance -= value;
			printf("Withdrawal made successfully!\n");
		}
	}
}

void insertClient(stack *stack, TClient client) {
	node *c = (node *) malloc(sizeof(node));
	
	if(c != NULL) {
		if(stack->top == NULL)	{
			c->client = client;
			c->next = NULL;
			stack->top = c;
		} else {
			c->next = stack->top;
			c->client = client;
			stack->top = c;
		}
		stack->count++;
	}
	printf("Done!\n");
}

TClient removeClient(stack *stack) {
	node *aux;
	TClient removedClient = stack->top->client;
	aux = stack->top;
	stack->top = stack->top->next;
	stack->count--;
	free(aux);
	return removedClient;
	
}

void displayClients(stack *stack) {
	if(isEmpty(stack)) {
		printf("Stack is empty!\n");
		exit(1);
	}
	node *aux;
	aux = stack->top;
	while(aux != NULL) {
		printf("\n-- DATA --\n");
		printf("CPF: %d\n", aux->client.cpf);
		printf("Name: %s\n", aux->client.name);
		printf("Address: %s\n", aux->client.address);
		printf("Telephone Number: %s\n", aux->client.tel);
		printf("Balance: %.2f\n", aux->client.balance);
		printf("\n\n");
		aux = aux->next;
	}
}

TClient createClient(TClient c) {
	printf("\n -- REGISTER -- \n");
	printf("CPF: \n");
	scanf("%d", &c.cpf);
	printf("Name: \n");
	scanf("%s", &c.name);
	printf("Address: \n");
	scanf("%s", &c.address);
	printf("Tel: \n");
	scanf("%s", &c.tel);
	printf("Balance: \n");
	scanf("%f", &c.balance);
	printf("\n\n");
	return c;
}

int getOpcao() {
	int opc;
	printf("\n -- MENU -- \n");
	printf("1. Insert client \n");
	printf("2. Remove client \n");
	printf("3. Withdraw amount \n");
	printf("4. Display clients \n");
	printf("5. Exit \n");
	scanf("%d", &opc);
	printf("\n\n");
	return opc;
}

void menu(int opc, stack *stack) {
	TClient client;
	int cpf;
	float value;
	
	switch(opc) {
		case 1: {
			client = createClient(client);
			insertClient(stack, client);
			break;
		} 
		case 2: {
			removeClient(stack);
			break;
		}
		case 3: {
			printf("CPF: \n");
			scanf("%d", &cpf);
			printf("Withdraw: \n");
			scanf("%f", &value);
			withdrawValue(stack, cpf, value);
			break;
		}
		case 4: {	
			displayClients(stack);
		}
		case 5: {	
			break;
		}
	}
}

#endif
