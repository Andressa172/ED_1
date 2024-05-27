#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<conio2.h>

struct Livro {
    char autores[256];
    char titulo_livro[256];
    char editora[100];
    int ano;
    int paginas;
};

struct TpListaAutor{
	char nome[100], sobrenome[100];
	TpListaAutor *prox;
};

struct TpAutor{
	TpAutor *prox;
	TpListaAutor *autor;
	
};

struct TpLivro{
	TpLivro *ant, *prox;
	char titulo_livro[256];
    int ano;
    int paginas;
    TpAutor *listaAutor;
};

struct TpEditora{
	char editora[100];
	TpEditora *prox;
	TpLivro *livro_prox;
};


struct TpDesc{
	int Qtde;
	TpEditora *inicio, *fim;
};


void importar_dados() {
    FILE *arquivo_txt = fopen("livros.txt", "r");
    FILE *arquivo_bin = fopen("livros.dat", "wb");

    if (arquivo_txt == NULL || arquivo_bin == NULL) {
        printf("Erro ao abrir arquivos");
        return;
    }

    
    Livro livro;
    
    
    fscanf(arquivo_txt, "%[^|] %[^] %[^|] %d %d", &livro.autores, &livro.titulo_livro, &livro.editora, &livro.ano, &livro.paginas);
    while(!feof(arquivo_txt)){
        fwrite(&livro, sizeof(struct Livro), 1, arquivo_bin);
        fscanf(arquivo_txt, "%[^|]%[^|]%[^|]%d%d", &livro.autores, &livro.titulo_livro, &livro.editora, &livro.ano, &livro.paginas);
    	
	}
    
    fclose(arquivo_txt);
    fclose(arquivo_bin);
}

void exibirbin() {
    FILE *arquivo_bin = fopen("livros.dat", "rb");

    if (arquivo_bin == NULL) {
        printf("Erro ao abrir arquivos");
        return;
    }
    
    Livro livro;
	
	fread(&livro, sizeof(Livro), 1, arquivo_bin);    
    while(!feof(arquivo_bin)){
        printf("%s %s %s %d %d", livro.autores, livro.titulo_livro, livro.editora, livro.ano, livro.paginas);
    	fread(&livro, sizeof(Livro), 1, arquivo_bin);	
	}
    
    fclose(arquivo_bin);
}




/*
void excluir_livro(char *titulo) {
    struct Livro *atual = cabeca;
    struct Livro *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->titulo_livro, titulo) == 0) {
            if (anterior == NULL) {
                cabeca = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    FILE *arquivo_bin = fopen("livros.dat", "wb");
    if (arquivo_bin == NULL) {
    	clrscr();
        printf("\nErro ao abrir arquivo binario\n");
        return;
    } 
    atual = cabeca;
    while (atual != NULL) {
        fwrite(atual, sizeof(struct Livro), 1, arquivo_bin);
        atual = atual->prox;
    }

    fclose(arquivo_bin);
}

void relatorio_por_autor() {
    struct Livro *atual = cabeca;
    while (atual != NULL) {
    	clrscr();
    	getch();
        printf("Autor: %s\n", atual->autores);
        printf("Titulo: %s\n", atual->titulo_livro);
        printf("Editora: %s\n", atual->editora);
        printf("Ano: %d\n", atual->ano);
        printf("Paginas: %d\n\n", atual->paginas);
        atual = atual->prox;
    }
}

void relatorio_por_editora() {
    struct Livro *atual = cabeca;
    while (atual != NULL) {
    	clrscr();
    	getch();
        printf("Editora: %s\n", atual->editora);
        printf("Autor: %s\n", atual->autores);
        printf("Titulo: %s\n", atual->titulo_livro);
        printf("Ano: %d\n", atual->ano);
        printf("Páginas: %d\n\n", atual->paginas);
        atual = atual->prox;
    }
}

void autores_sem_livro() {
    char *todos_autores[] = {
        "ZIVIANI, Nivio", "CELES, Waldemar", "CERQUEIRA, Renato",
        "RANGEL NETTO, José Lucas Mourão", "PEREIRA, Silvio do Lago",
        "TENENBAUM, Aaron M.", "LANGSAM, Yedidyah", "AUGENSTEIN, Moshe",
        "SOUZA, Teresa Cristina Felix", "SANTOS, Cleisio Saraiva",
        "FURTADO, Antonio", "VELOSO, Paulo A. S.", "SALIBA, Walter Luiz Caram",
        "ASSUMPÇÃO FILHO, Milton Mira de", "SZWARCFITER, Jayme Luiz",
        "MARKENZON, Lilian", "WIRTH, Niklaus", "CHENG, Mei Lee"
    };
    int num_autores = sizeof(todos_autores) / sizeof(todos_autores[0]);
    int possui_livro[num_autores];
    memset(possui_livro, 0, sizeof(possui_livro));

    struct Livro *atual = cabeca;
    while (atual != NULL) {
        for (int i = 0; i < num_autores; i++) {
            if (strstr(atual->autores, todos_autores[i]) != NULL) {
                possui_livro[i] = 1;
            }
        }
        atual = atual->prox;
    }

    printf("Autores sem livros:\n");
    for (int i = 0; i < num_autores; i++) {
        if (!possui_livro[i]) {
            printf("%s\n", todos_autores[i]);
        }
    }
}
*/
void menu() {
	clrscr();
    printf("\nMenu:\n");
    printf("[1] Importar dados do arquivo txt para bin\n");
    printf("[2] Construir estrutura dinamica\n");
    printf("[3] Excluir um livro\n");
    printf("[4] Relatório\n");
    printf("[5] Sair\n");
    printf("Escolha uma opção: ");
}

int main(void) {
    int opcao;
    char titulo[256];

    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                importar_dados();
                exibirbin();
                break;
            case 2:
                //construir_estrutura();
                break;
            case 3:
                printf("Digite o título do livro a ser excluído: ");
                scanf(" %[^\n]", titulo);
                //excluir_livro(titulo);
                break;
            case 4:
                printf("[RELATORIO]\n[1] - Todos os livros de cada AUTOR\n");
                printf("[2] - Todos os livros de cada EDITORA\n");
                printf("[3] - Todos os nomes de autores que não possuem livro\n");
                int rel_opcao;
                scanf("%d", &rel_opcao);
                if (rel_opcao == 1) {
                    //relatorio_por_autor();
                } else if (rel_opcao == 2) {
                    //relatorio_por_editora();
                } else if (rel_opcao == 3) {
                    //autores_sem_livro();
                } else {
                    printf("Opcao de relatorio invalida!\n");
                }
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        	
        	
        }
        getch();
    } while (opcao != 5);

    return 0;
}

