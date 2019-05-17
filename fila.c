#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Lista por alocação dinâmica em C
typedef struct datanode{
	int mat;
	char nome[40];
	int idade;
}DataNode;

typedef struct node{
	DataNode data;
	struct node* next;
}Node;

typedef struct lista{
	int tam;
	struct node* primeiro;
	struct node* ultimo;
}Lista;
/////////////////////////////////////////////////////////////////////////
Lista* cria(Lista* lista){
	lista = (Lista*)malloc(sizeof(Lista));
	lista->primeiro = NULL;
	lista->ultimo = NULL;
	lista->tam = 0
	return lista;
}

Lista* insere(Lista* lista, DataNode node){

	if(lista->primeiro == NULL && lista->ultimo == NULL){
		lista->primeiro = (Node*)malloc(sizeof(Node));
		lista->ultimo = lista->primeiro;
		lista->primeiro->next = NULL;
		lista->primeiro->data = node;
		lista->tam = 1;
	}
	else{
		lista->primeiro->next = (Node*)malloc(sizeof(Node));
		lista->ultimo = lista->primeiro->next;
		lista->ultimo->data = node;
		lista->ultimo->next = NULL;
		lista->tam = lista->tam + 1;
	}

	return lista;
}

Lista* retira(Lista* lista){//Essa função retira no começo da lista

	Node* ptr = NULL;

	ptr = lista->primeiro;

	lista->primeiro = lista->primeiro->next;

	free(ptr);

	return lista;
}

void printa(Lista* lista){

	Node* node = lista->primeiro;
	int i = 0;

	while(node != NULL){

		i++;
		printf("Número %d\n", i);
		printf("Nome: %s \n",node->data.nome);
		printf("Matrícula: %d \n",node->data.mat);
		printf("Idade: %d \n",node->data.idade);
		printf("\n");
		node = node->next;
	}

	printf("\n");
	free(node);
}
/////////////////////////////////////////////////////////////////////////
void main(){

	Lista* lista;
	DataNode dados;
	
	lista = cria(lista);
	int op;

	do{
		printf("1 - Inserir\n");
		printf("2 - Retirar\n");
		printf("3 - Printar\n");
		printf("0 - Sair\n");
		scanf("%d",&op);

		if(op == 1){

			printf("Qual é o nome do pirralho ?\n");
			setbuf(stdin,NULL);
			scanf("%[^\n]s", dados.nome);

			printf("Qual é o número de matrícula?\n");
			scanf("%d",&dados.mat);

			printf("Qual é a idade ?\n");
			scanf("%d",&dados.idade);

			lista = insere(lista,dados);
		}

		if(op == 2){
			lista = retira(lista);
		}

		if(op == 3){
			printa(lista);
		}

	}while(op != 0);

	free(lista);
	printf("debug");
}
/////////////////////////////////////////////////////////////////////////