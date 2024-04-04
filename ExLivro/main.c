#include <stdio.h>
#include <string.h>

#define MAX_TITULO 100
#define MAX_AUTOR 50

//Controle de Biblioteca

typedef struct{
	char titulo[MAX_TITULO];
	char autor[MAX_AUTOR];
	int ano;
} Livro;

void adicionar(Livro *biblioteca, int *quantidade){
	printf("Digite o titulo do livro: ");
    getchar();
	fgets(biblioteca[*quantidade].titulo, sizeof(biblioteca[*quantidade].titulo), stdin);
	biblioteca[*quantidade].titulo[strcspn(biblioteca[*quantidade].titulo, "\n")] = '\0';
	
	printf("Digite o nome do autor: ");
    getchar();
	fgets(biblioteca[*quantidade].autor, sizeof(biblioteca[*quantidade].autor), stdin);
	biblioteca[*quantidade].autor[strcspn(biblioteca[*quantidade].autor, "\n")] = '\0';
	
	
	printf("Digite o ano do livro: ");
	scanf("%d", &biblioteca[*quantidade].ano);
    getchar();
	
	(*quantidade)++;
}

void listar(Livro *biblioteca, int quantidade){
	int i;
	if(quantidade == 0){
		printf("Nenhum Livro registrado...");
		return;
	}
	for(i = 0; i < quantidade; i++){
	printf("\nLivro_____%d", i);
	printf("\nTitulo____%s", biblioteca[i].titulo);
	printf("\nAutor_____%s", biblioteca[i].autor);
	printf("\nAno_______%d\n", biblioteca[i].ano);
}
}

void buscarLivroPorTitulo(Livro *biblioteca, int quantidade ,char *tituloBusca){
	int encontrado = 0;
	int i;
	for(i = 0; i < quantidade; i++){
		if(strcmp(biblioteca[i].titulo, tituloBusca) == 0){
			printf("\nLivro encontrado: ");
			printf("\nLivro_____%d", i);
			printf("\nTitulo____%s", biblioteca[i].titulo);
			printf("\nAutor_____%s", biblioteca[i].autor);
			printf("\nAno_______%d", biblioteca[i].ano);
			encontrado = 1;
			break;
		}
    }
		if(!encontrado){
			printf("\nLivro nao encontrado...\n");
		}
	
}

int main() {
	Livro biblioteca[100];
	int op, quantidade = 0;
	char tituloBusca[MAX_TITULO];
	
	do{
		printf("\n\nSelecione uma opcao:");
		printf("\n1 - add livro");
		printf("\n2 - listar livros");
		printf("\n3 - Buscar pelo titulo");
		printf("\n4 - Sair");
		printf("\nOpcao: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				adicionar(biblioteca, &quantidade);
				break;
			case 2:
				listar(biblioteca, quantidade);
				break;
			case 3:
				printf("Qual e o titulo do livro: ");
                getchar();
				fgets(tituloBusca, sizeof(tituloBusca), stdin);
                tituloBusca[strcspn(tituloBusca, "\n")] = '\0';
				buscarLivroPorTitulo(biblioteca, quantidade, tituloBusca);
				break;
			case 4:
				
				printf("Saindo...");
				break;
			default:
				printf("Opcao Invalida!");
				break;
		}
	}while(op != 4);
	
	return 0;
}
