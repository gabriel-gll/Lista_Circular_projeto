#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct no{
    int valor;
    char nome[30];
    struct no *proximo;
    int pos;
}No;

typedef struct lista{
    No *inicio;
    No *fim;
    int tam;
}Lista;

void criar_lista(Lista *lista);

void inserir_no_inicio(Lista *lista, int num, char string[30]);

void inserir_no_fim(Lista *lista, int num, char string[30]);

No* remover(Lista *lista, int num);

void inserir_no_meio(Lista *lista, int num, int ant, char string[30]);

No* remover_no_inicio(Lista *lista);

void imprimir(Lista *lista);

int tamanho(Lista *lista);

void mostrar_ordenado(Lista *lista);

No* remover_no_meio(Lista *lista, int pos);

No* remover_maior_elemento(Lista *lista);

void imprimi_elemento(No *aux);

int lista_esta_vazia(Lista *l);

void desaloca(Lista *l);

int retorna_inteiro(No *aux);

char* retorna_string(No* aux);

#endif