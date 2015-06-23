#include "ArvBin.h"
#include<stdio.h>

int main() {
    ABB *minhaArv = criarArvore();

    if (estahVazia(minhaArv))
        printf("Arvore vazia!\n");

    inserir(minhaArv, 3);
    inserir(minhaArv, 1);
    inserir(minhaArv, 2);
    inserir(minhaArv, 4);
    inserir(minhaArv, 0);

    remover(minhaArv, 3);

    preOrdem(minhaArv);

    int h, tam;
    obterAltura(minhaArv, &h);
    obterTamanho(minhaArv, &tam);
    printf("h = %d, tam = %d\n", h, tam);


/*  minhaArv = inserir(minhaArv, 5);
    minhaArv = inserir(minhaArv, 3);
    minhaArv = inserir(minhaArv, 7);
    minhaArv = inserir(minhaArv, 4);
    minhaArv = inserir(minhaArv, 6);
    preOrdem(minhaArv);
    printf("\n");
    inOrdem(minhaArv);
    printf("\n");
    posOrdem(minhaArv);

    if (buscar(minhaArv, 8) == TRUE)
        printf("\nElemento encontrado!\n");
    else
        printf("\nElemento não encontrado!\n");

*/
    return 0;
}

