#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_circular.h"

int main(){
    srand(time(NULL));
    int opcao,valor,anterior,tam,n=0,i=0,j=0;
    int x=0,cont=0,salto=0;
    Lista *lista=(Lista*)malloc(sizeof(Lista));
    No *removido;
    No *aux;
    int rad=0;
    char nome[30];
    criar_lista(lista);

    printf("Digite a quantidade de soldados q vc deseja criar\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        inserir_no_fim(lista,i,"soldado");
    }
    imprimir(lista);
    tam=tamanho(lista);
    tam=tam*2;


    if(n !=1){
        do{
            salto=0;
            tam=tamanho(lista);
            tam=tam*2;
            x=rand()%tam;
            if(cont==0){
                aux=lista->inicio;
            }
            cont++;
            do{
                if(x==0 && rad==1){
                    do{
                        x=rand()%tam;
                    }while(x == 0);
                }
                if(x != salto){
                    salto++;
                    aux=aux->proximo;
                    rad=1;
                }
            }while(salto != x && rad != 0);
            removido=remover(lista,aux->valor);
            printf("\nFoi removido o elemento: \n");
            imprimi_elemento(aux);
            printf("\nEstado atual da lista: \n");
            imprimir(lista);
        }while(lista->tam > 1);
        aux=aux->proximo;
        printf("\nO soldado sobrevivente foi: \n");
        imprimi_elemento(aux);
    }else{
        printf("\nO soldado sobrevivente foi: \n");
        aux=lista->inicio;
        imprimi_elemento(aux);
    }
    desaloca(lista);
    free(removido);
    return 0;
}