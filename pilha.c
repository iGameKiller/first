#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//EU ESTOU MUITO ORGULHOSO DE MIM, EU SOU BOM NO QUE FAÇO E TO FICANDO BOM, E EU SOU UMA PESSOA BOA

typedef struct datanode{
	int idade;
	char nome[40];
	int mat;
}DataNode;

typedef struct node{
	DataNode node;
	struct node* prox;
}Node;

typedef struct pilha{
	int tam;
	struct node* topo;
	struct node* base;
}Pilha;
///////////////////////////////////////////////////////////////////////////////
Pilha* cria(Pilha* pilha){

	pilha = (Pilha*)malloc(sizeof(Pilha));
	pilha->topo = NULL;
	pilha->tam = 0;

	return pilha;
}

Pilha* empilha(Pilha* pilha, DataNode data){

	if(pilha->topo == NULL && pilha->base == NULL){

		pilha->topo = (Node*)malloc(sizeof(Node));
		pilha->base = pilha->topo;
		pilha->base->node = data;
		pilha->base->prox = NULL;
		pilha->tam = 1;
	}
	else{
		pilha->base->prox = (Node*)malloc(sizeof(Node));
		pilha->base = pilha->base->prox;
		pilha->base->prox = NULL;
		pilha->base->node = data;
		pilha->tam = pilha->tam + 1;
	}
}

Pilha* desempilha(Pilha* pilha){

	Node* ptr = NULL;

	ptr = pilha->topo;
	pilha->topo = pilha->topo->prox;

	free(ptr);

	return pilha;
}

void printa(Pilha* pilha){

	system("clear");
	Node* ptr;

	ptr = pilha->topo;
	int i = 0;

	do{
		printf("Idade: %d\n", ptr->node.idade);
		printf("Matrícula: %d\n",ptr->node.mat);
		printf("Nome: %s\n",ptr->node.nome);
		printf("\n");
		ptr = ptr->prox;
		i++;
	}while(i != pilha->tam);

	free(ptr);

	printf("\n");
}
///////////////////////////////////////////////////////////////////////////////
int main(){

	Pilha* pilha;
	DataNode data;
	int op;

	pilha = cria(pilha);

	do{
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Printar\n");
		printf("0 - Sair\n");
		scanf("%d",&op);

		switch(op){

			case 0:
				free(pilha);
				return 0;
			break;

			case 1:
				printf("Qual é a idade ?\n");
				scanf("%d",&data.idade);

				printf("Qual é o nome do pirralho ?\n");
				setbuf(stdin,NULL);
				scanf("%[^\n]s",data.nome);

				printf("Qual é a matrícula ?\n");
				scanf("%d",&data.mat);

				pilha = empilha(pilha,data);
			break;

			case 2:
				pilha = desempilha(pilha);
			break;

			case 3:
				printa(pilha);
			break;
		}

	}while(op != 0);

	free(pilha);
}