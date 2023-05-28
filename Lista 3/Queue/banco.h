#ifndef __BANCO__
#define __BANCO__
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int cpf;
	char name[50];
	char adress[40];
	char tel[10];
	float balance;
} TClient;

struct Node {
	TClient client;
	struct Node *next;
};

typedef struct Node node;

struct queue {
	int count;
	node *front;
	node *rear;
};

typedef struct queue queue;

void startQueue(queue *queue) {
	queue->count = 0;
	queue->front = NULL;
	queue->rear = NULL;
}

int isEmpty(queue *queue) {
	return queue->rear == NULL;
}

node * verifyClient(queue *queue, int cpf) {
	node *aux;
	if(!isEmpty(queue)) {
		aux = queue->front;
		while(aux != NULL) {
			if(aux->client.cpf == cpf) {
				return aux;
			}
			aux = aux->next;
		}
		return NULL;
	}
}

void withdrawValue(queue *queue, int cpf, float value) {
	node *aux = verifyClient(queue, cpf);
	if(aux != NULL) {
		if(aux->client.balance < value) {
			printf("Insuficient balance!\n");
		} else {
			aux->client.balance -= value;
			printf("Withdraw done successfully!\n");
		}
	}
}

void insertClient(queue *queue, TClient client) {
	node *newClient = (node *) malloc(sizeof(node)); // cria-se um novo nó
	if(!newClient) {
		printf("No available memory!\n");
		exit(1);
	}
	newClient->client = client; // adiciona um cliente ao nó criado
	newClient->next = NULL; // atribui NULL no endereço do próximo nó
	if (isEmpty(queue)) { // se lista estiver vazia
		queue->front = newClient; // front recebe o endereço do primeiro elemento da fila
		queue->rear = newClient; // rear recebe o endereço do último elemento da fila
	} else { // se fila não estiver vazia
		queue->rear->next = newClient; // o último nó irá receber o endereço do último elemento da fila no seu next
		queue->rear = newClient; // o novo elemento inserido na fila será o último
	}
	queue->count++; // incrementa o contador de elementos
}

TClient removeClient(queue *queue) {
	node *removedClient; // ponteiro de node
	TClient client = queue->front->client; // retira-se o cliente da primeira posição da fila
	removedClient = queue->front;  // ponteiro da primeira posição é atribuído ao removedClient
	queue->front = queue->front->next; // o cliente a seguir do primeiro cliente é transferido para a primeira posição da fila
	queue->count--; // decrementa o contador de clientes da fila
	free(removedClient); // libera posição de memória
	return client; // retorna o cliente removido
}

void displayClients(node *head) {
	
	if(head == NULL) { // se o primeiro elemento for nulo, significa que a fila está vazia
		printf("Queue is empty!\n");
		exit(1);
	}
	
	node *aux; // cria-se um ponteiro para um nó
	aux = head; // o nó auxiliar recebe o primeiro cliente
	
	while(aux != NULL) { 
		printf("\n-- Cliente --\n");
		printf("CPF: %d\n", aux->client.cpf);
		printf("Nome: %s\n", aux->client.name);
		printf("Endereco: %s\n", aux->client.adress);
		printf("Telefone: %s\n", aux->client.tel);
		printf("Saldo: %.2f\n", aux->client.balance);
		printf("\n\n");
		aux = aux->next; // aux recebe o próximo nó da fila
	}
}

TClient createClient(TClient c) {
	printf("\n Preencha os dados\n");
	printf("CPF: \n");
	scanf("%d", &c.cpf);
	printf("Nome: \n");
	scanf("%s", &c.name);
	printf("Endereco: \n");
	scanf("%s", &c.adress);
	printf("Telefone: \n");
	scanf("%s", &c.tel);
	printf("Saldo: \n");
	scanf("%f", &c.balance);
	printf("\n\n");
	return c;
}

int getOpcao() {
	int opc;
	printf("\n -- MENU -- \n");
	printf("1. Inserir cliente \n");
	printf("2. Remover cliente \n");
	printf("3. Sacar quantia \n");
	printf("4. Listar clientes \n");
	printf("5. Sair \n");
	scanf("%d", &opc);
	printf("\n\n");
	return opc;
}

void menu(int opc, queue *queue) {
	TClient client;
	int cpf;
	float value;
	
	switch(opc) {
		case 1: {
			client = createClient(client);
			insertClient(queue, client);
			break;
		} 
		case 2: {
			removeClient(queue);
			break;
		}
		case 3: {
			printf("Digite o CPF: \n");
			scanf("%d", &cpf);
			printf("Digite o valor a ser retirado: \n");
			scanf("%f", &value);
			withdrawValue(queue, cpf, value);
			break;
		}
		case 4: {	
			displayClients(queue->front);
		}
		case 5: {	
			break;
		}
	}
}
#endif
