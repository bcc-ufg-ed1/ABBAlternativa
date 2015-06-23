#include "ArvBin.h"
#include<stdlib.h>

ABB* criarArvore() {
    ABB *abb = malloc(sizeof(*abb));
    if (abb == NULL)
        return NULL;
    abb->raiz = NULL;
    abb->tam = 0;
    return abb;
}

int obterAlturaR(No* raiz) {
    if (raiz == NULL)
        return -1;
    int hSae, hSad;
    hSae = obterAlturaR(raiz->sae);
    hSad = obterAlturaR(raiz->sad);
    if (hSae > hSad)
        return (1 + hSae);
    return (1 + hSad);
}

int obterAltura(ABB* arv, int *h) {
    if (arv == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    *h = obterAlturaR(arv->raiz);
    return OK;
}

int obterTamanho(ABB* arv, int *tam) {
    if (arv == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    *tam = arv->tam;
    return OK;
}


int estahVazia(ABB* arv) {
    if (arv == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (arv->raiz == NULL)
        return TRUE;
    return FALSE;
}

No* criarNoFolha(int item) {
    No* folha = malloc(sizeof(*folha));
    if (folha == NULL)
        return NULL;
    folha->item = item;
    folha->sae = NULL; folha->sad = NULL;
    return folha;
}

int buscarR(No* arv, int item) {
    if (arv == NULL)
        return FALSE;
    if (item < arv->item)
        return buscarR(arv->sae, item);
    if (item > arv->item)
        return buscarR(arv->sad, item);
    return TRUE;
}

int buscar(ABB* arv, int item) {
    if (arv == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    return buscarR(arv->raiz, item);
}

No* inserirR(No* arv, int item) {
    if (arv == NULL)
        return criarNoFolha(item);
    if (item < arv->item)
        arv->sae = inserirR(arv->sae, item);
    if (item > arv->item)
        arv->sad = inserirR(arv->sad, item);
    return arv;
}

int inserir(ABB* arv, int item) {
    if (arv == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    arv->raiz = inserirR(arv->raiz, item);
    arv->tam++;
    return OK;
}

No* removerR(No* arv, int item) {
    if (arv == NULL) // não encontrou elemento para remover
        return NULL;
    if (item < arv->item)
        arv->sae = removerR(arv->sae, item);
    else if (item > arv->item)
        arv->sad = removerR(arv->sad, item);
    else {
        if ((arv->sae == NULL) && (arv->sad == NULL)) { // É um nó folha.
            free(arv);
            arv = NULL;
        } else if (arv->sae == NULL) {		    // Tem apenas um filho à direita.
            No* aux = arv;
            arv = arv->sad;
            free(aux);
            aux = NULL;
        } else if (arv->sad == NULL) {		    // Tem apenas um filho à esquerda.
            No* aux = arv;
            arv = arv->sae;
            free(aux);
            aux = NULL;
        } else {
            No* aux = arv->sae;
            while(aux->sad != NULL) {
                aux = aux->sad;
            }
            arv->item = aux->item; aux->item = item;
            arv->sae = removerR(arv->sae, item);
        }
    }
    return arv;
}

int remover(ABB* arv, int item) {
    if (arv == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    arv->raiz = removerR(arv->raiz, item);
    arv->tam--;
    return OK;
}

void preOrdemR(No* arv) {
    if (arv != NULL) {
      printf("%d ", arv->item);
      preOrdemR(arv->sae);
      preOrdemR(arv->sad);
    }
}

void inOrdemR(No* arv) {
    if (arv != NULL) {
      inOrdemR(arv->sae);
      printf("%d ", arv->item);
      inOrdemR(arv->sad);
    }
}

void posOrdemR(No* arv) {
    if (arv != NULL) {
      posOrdemR(arv->sae);
      posOrdemR(arv->sad);
      printf("%d ", arv->item);
    }
}

int preOrdem(ABB* arv) {
    if (arv == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    preOrdemR(arv->raiz);
}

int inOrdem(ABB* arv) {
    if (arv == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    inOrdemR(arv->raiz);
    return OK;
}

int posOrdem(ABB* arv) {
    if (arv == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    posOrdemR(arv->raiz);
    return OK;
}
