#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_circular.h"

int main(){
    srand(time(NULL));
    int opcao,valor,anterior,tam=0,n=0,i=0,j=0;
    int x=0,cont=0,salto=0,posicao=0;
    Lista *lista=(Lista*)malloc(sizeof(Lista));
    No *removido;
    No *aux;
    int rad=0;
    char nome[30];
    criar_lista(lista);


    do{
        printf("\n\t0 - Sair\n\t1 - Verificar se a lista esta vazia\n\t2 - Inserir no inicio\n\t3 - Inserir em posicao\n\t4 - Inserir no final\n\t5 - Remover no inicio\n\t6 - Remover elemento em posicao\n\t7 - Tamanho da lista atual\n\t8 - Retorna o maior elemento da lista, removendo-o\n\t9 - Imprimir Lista\n\t10 - Desaloca todos elementos\n\t11 - Mostra em ordem de forma crescente\n");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                if(!lista_esta_vazia(lista)){
                    printf("A lista nao esta vazia\n");
                }else{
                    printf("A lista esta vazia\n");
                }
                break;
            case 2:
                printf("Digite um valor para inserir no inicio: \n");
                scanf("%d",&valor);
                printf("Digite a string para inserir junto com o valor \n");
                fflush(stdin);
                fgets(nome,30,stdin);
                nome[strcspn(nome, "\n")]=0;
                inserir_no_inicio(lista,valor,nome);
                break;
            case 3:
                printf("Digite em qual posicao a insercao sera realizada (obs: a primeira posicao e a posicao 0)\n");
                printf("Lista: \n");
                imprimir(lista);
                scanf("%d",&posicao);
                printf("Digite um valor para a insercao na posicao escolhida\n");
                scanf("%d",&valor);
                printf("Digite a string para inserir junto com o valor\n");
                fflush(stdin);
                fgets(nome,30,stdin);
                nome[strcspn(nome, "\n")]=0;
                inserir_no_meio(lista,valor,posicao,nome);
                break;
            case 4:
                printf("Digite um valor para a insercao no final\n");
                scanf("%d",&valor);
                printf("Digite a string para inserir junto com o valor\n");
                fflush(stdin);
                fgets(nome,30,stdin);
                nome[strcspn(nome, "\n")]=0;
                inserir_no_fim(lista,valor,nome);
                break;
            case 5:
                removido=remover_no_inicio(lista);
                if(removido != NULL){
                    printf("Elemento removido: \n");
                    imprimi_elemento(removido);
                    free(removido);
                }
                break;
            case 6:
                printf("Digite em qual posicao a remocao sera realizada (obs: a primeira posicao e a posicao 0)\n");
                printf("Lista: \n");
                imprimir(lista);
                scanf("%d",&posicao);
                removido=remover_no_meio(lista,posicao);
                if(removido != NULL){
                    printf("Elemento removido: \n");
                    imprimi_elemento(removido);
                    free(removido);
                }
                break;
            case 7:
                tam=tamanho(lista);
                printf("O tamanho da lista e: %d",tam);
                break;
            case 8:
                removido=remover_maior_elemento(lista);
                if(removido != NULL){
                    printf("Elemento removido: \n");
                    imprimi_elemento(removido);
                    free(removido);
                }
                break;
            case 9:
                imprimir(lista);
                break;
            case 10:
                desaloca(lista);
                if(lista == NULL){
                    printf("Elementos da lista desalocados\n");
                }
                break;
            case 11:
                printf("Valores da lista em ordem crescente: \n");
                mostrar_ordenado(lista);
                break;
            default:
                if(opcao != 0){
                    printf("Opcao invalida!\n");
                }
        }

    }while(opcao != 0);
    return 0;
}