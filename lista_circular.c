#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_circular.h"

void criar_lista(Lista *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
    lista->tam=0;
}

void inserir_no_inicio(Lista *lista, int num, char string[30]){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        strcpy(novo->nome,string);
        novo->pos=0;
        novo->proximo=lista->inicio;
        lista->inicio=novo;
        if(lista->fim == NULL){
            lista->fim=novo;
        }
        lista->fim->proximo=lista->inicio;
        lista->tam++;
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

void inserir_no_fim(Lista *lista, int num, char string[30]){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        strcpy(novo->nome,string);
        novo->pos=0;

        // é o primeiro?
        if(lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }
        else{
            lista->fim->proximo = novo;
            lista->fim = novo;
            novo->proximo = lista->inicio;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimir(Lista *lista){
    No *no = lista->inicio;
    printf("\n\tLista tam %d: ", lista->tam);
    if(no){
        do{
            imprimi_elemento(no);
            no = no->proximo;
        }while(no != lista->inicio);
        printf("\nInicio: %d\n", no->valor);
    }
    printf("\n\n");
}

void inserir_no_meio(Lista *lista, int num, int ant, char string[30]){
    No *aux, *novo=malloc(sizeof(No));
    aux=lista->inicio;
    int cont=0;
    novo->pos=0;
    int tam=0;

    tam=tamanho(lista);

    if(!lista_esta_vazia(lista)){

        if(ant > tam || ant < 0){
        printf("Posicao invalida!\n");
        }else{

        do{
            aux->pos=cont;
            cont++;
            aux = aux->proximo;
        }while(aux != lista->inicio);

        if(novo){
            novo->valor = num;
            strcpy(novo->nome,string);
            if(lista->inicio == NULL){
                lista->inicio = novo;
                lista->fim = novo;
                lista->fim->proximo = lista->inicio;
            }
            else if(ant == 0){
                novo->proximo=lista->inicio;
                novo->pos=0;
                lista->inicio=novo;
                if(lista->fim == NULL){
                    lista->fim=novo;
                }
            lista->fim->proximo=lista->inicio;          
            }
            else{
                aux=lista->inicio;
                do{
                    aux=aux->proximo;
                    if(aux->pos+1 == ant && aux->proximo == lista->inicio){
                        lista->fim->proximo=novo;
                        lista->fim=novo;
                        novo->proximo=lista->inicio;
                    }
                    else if(aux->pos+1 == ant && aux->proximo != lista->inicio){
                        novo->proximo=aux->proximo;
                        aux->proximo=novo;
                    }
                    
                }while(aux->pos+1 !=ant && aux != lista->inicio);
            }
            lista->tam++;
        }
        else{
            printf("Erro ao alocar memoria!\n");
        }
    }
    }else{
        if(ant == 0){
            novo->valor=num;
            strcpy(novo->nome,string);
            inserir_no_inicio(lista,novo->valor,novo->nome);
        }else{
            printf("Posicao invalida!\n");
        }
    }
}

No* remover(Lista *lista, int num){
    No *aux, *remover = NULL;

    if(lista->inicio){
        if(lista->inicio == lista->fim && lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
        }
        else if(lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo->valor == num){
                if(lista->fim == aux->proximo){
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    lista->fim = aux;
                }
                else{
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
                lista->tam--;
            }
        }
    }
    return remover;
}

No *remover_no_inicio(Lista *lista){
    No *aux, *remover=NULL;
    if(lista->inicio){
        if(lista->inicio == lista->fim){
            remover=lista->inicio;
            lista->inicio=NULL;
            lista->fim=NULL;
            lista->tam--;
        }else{
            remover=lista->inicio;
            lista->inicio=remover->proximo;
            lista->fim->proximo=lista->inicio;
            lista->tam--;
        }
    }
    return remover;
}

int tamanho(Lista *lista){
    int cont=0;
    No *no=lista->inicio;
        if(no){
        do{
            cont++;
            no = no->proximo;
        }while(no != lista->inicio);
    }
    return cont;
}

void mostrar_ordenado(Lista *lista){
    int tam,i=0,j,aux;
    tam=tamanho(lista);
    int *vet;
    vet=(int*)malloc(tam*sizeof(int));
    No *no=lista->inicio;
    if(no){
        do{
            no=no->proximo;
            vet[i]=no->valor;
            i++;
        }while(no !=lista->inicio);
    
        for(i=0;i<tam;i++){
            for(j=i+1;j<tam;j++){
                if(vet[i] > vet[j]){
                    aux=vet[i];
                    vet[i]=vet[j];
                    vet[j]=aux;
                }
            }
        }
        printf("A lista ordenada: \n");
        for(i=0;i<tam;i++){
            do{
                no=no->proximo;
                if(no->valor == vet[i]){
                    imprimi_elemento(no);
                }

            }while(no->valor != vet[i]);
        }
    }
}

No* remover_no_meio(Lista* lista, int pos) {
    No* aux;
    No* remover = NULL;
    aux = lista->inicio;
    int cont = 0,tam=0;

    tam=tamanho(lista);

    do {
        aux->pos = cont;
        cont++;
        aux = aux->proximo;
    } while (aux != lista->inicio);

    if(pos > tam-1 || pos < 0){
        printf("Falha, posicao invalida\n");
    }
    else{
        
        if (lista->inicio) {
            if (lista->inicio == lista->fim && aux->pos == pos) {
                remover = lista->inicio;
                lista->inicio = NULL;
                lista->fim = NULL;
            }
            else if(lista->inicio->pos == pos){
                remover=lista->inicio;
                lista->inicio=remover->proximo;
                lista->fim->proximo=lista->inicio;
            }
            else {
                aux=lista->inicio;
                do {
                    if(aux->proximo->pos == pos){
                        if(lista->fim == aux->proximo){
                            remover=aux->proximo;
                            aux->proximo=remover->proximo;
                            lista->fim=aux;
                        }
                        else{
                            remover=aux->proximo;
                            aux->proximo=remover->proximo;
                        }
                    }
                    aux=aux->proximo;
                } while (aux->pos != pos && aux != lista->inicio);
            }
            lista->tam--;
        }
        return remover;
    }
}

No* remover_maior_elemento(Lista *lista){
    int tam=0,i=0,j=0,aux=0;
    int maior=0;
    tam=tamanho(lista);
    int *vet=(int*)malloc(tam*sizeof(int));
    No *no=lista->inicio;
    No *removido=NULL;
    if(no){
        do{
            no=no->proximo;
            vet[i]=no->valor;
            i++;
        }while(no !=lista->inicio);

        for(i=0;i<tam;i++){
            for(j=i+1;j<tam;j++){
                if(vet[i] > vet[j]){
                    aux=vet[i];
                    vet[i]=vet[j];
                    vet[j]=aux;
                }
            }
        }
        for(i=0;i<tam;i++){
            maior=vet[i];
        }
        printf("O maior e %d\n",maior);
        removido=remover(lista,maior);
        free(vet);
        return removido;
    }
}

void imprimi_elemento(No *aux){
    printf("| %d-%s | ",aux->valor,aux->nome);
}

int lista_esta_vazia(Lista *l){
    return (l->inicio == NULL);
}

void desaloca(Lista *l){
    Lista *aux=l;
    if(aux != NULL){
        if(!lista_esta_vazia(aux)){
            No *p=aux->inicio;

            while(p != aux->fim){
                No *q=p;
                p=p->proximo;
                free(q);
            }
            free(p);            
        }
        free(aux);
        l=NULL;
    }
}

int retorna_inteiro(No* aux){
    return aux->valor;
}

char* retorna_string(No* aux){
    char *p;
}