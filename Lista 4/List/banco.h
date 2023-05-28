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

void startList(node *list) {
	list->next = NULL;
}

int isEmpty(node *list) {
	return list->next == NULL;
}

node * verifyClient(node *list, int cpf) {
	node *aux;
	aux = list;
	if(!isEmpty(list)) {
		while(aux != NULL) {
			if(aux->client.cpf == cpf)
				return aux;
			aux = aux->next;
		}
	} 
	return NULL;
}

void withdrawAmount(node *list, int cpf, float amount) {
	node *c = verifyClient(list, cpf);
	if(c != NULL) {
		if(c->client.balance < amount) {
			printf("Insuficient funds!\n");
		} else {
			c->client.balance -= amount;
			printf("Withdrawal made successfully!\n");
		}
	}
}

void insertClient(node *list, TClient client) {
	node *newClient = (node*) malloc(sizeof(node));
	if(!newClient) {
		printf("No available memory!\n");
		exit(1);
	}
	newClient->client = client;
	newClient->next = NULL;
	if(isEmpty(list)) {
		list->next = newClient;
	} else {
		node *lastClient = list->next;
		while(lastClient->next != NULL) {
			lastClient = lastClient->next;
		}	
		lastClient->next = newClient;
	}
	printf("Done!\n");
}

TClient removeClient(node *list, int cpf) {
	node *removedClient = verifyClient(list, cpf);
	TClient client = removedClient->client;
	node *aux = list;
	while(aux != NULL) {
		if(aux->next == removedClient) {
			node *before = aux;
			aux->next = removedClient->next;
			free(removedClient);
			return client;
		}
		aux = aux->next;
	}
}

void displayClients(node *list) {
	if(isEmpty(list)){
		printf("List is empty!\n");
		return;
	}
	node *aux;
	aux = list->next;
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

int getOption() {
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

void menu(int opc, node *list) {
	TClient client;
	int cpf;
	float value;
	
	switch(opc) {
		case 1: {
			client = createClient(client);
			insertClient(list, client);
			break;
		} 
		case 2: {
			printf("CPF: \n");
			scanf("%d", &cpf);
			client = removeClient(list, cpf);
			printf("%d was removed from list!\n", client.cpf);
			break;
		}
		case 3: {
			printf("CPF: \n");
			scanf("%d", &cpf);
			printf("Amount: \n");
			scanf("%f", &value);
			withdrawAmount(list, cpf, value);
			break;
		}
		case 4: {	
			displayClients(list);
		}
		case 5: {	
			break;
		}
	}
}
#endif
