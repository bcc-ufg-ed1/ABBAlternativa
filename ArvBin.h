#ifndef ARV_BIN_H
#define ARV_BIN_H

#define TRUE 1
#define FALSE 0

#define OK 0
#define ESTRUTURA_NAO_INICIALIZADA -1

typedef struct {
    int item;
    struct No *sae;
    struct No *sad;
} No;

typedef struct {
    int tam;
    No *raiz;
} ABB;

ABB* criarArvore();
int estahVazia(ABB* arv);
int buscar(ABB* arv, int item);
int inserir(ABB* arv, int item);
int remover(ABB* arv, int item);
int obterAltura(ABB* arv, int *h);
int obterTamanho(ABB* arv, int *tam);
int preOrdem(ABB* arv);
int inOrdem(ABB* arv);
int posOrdem(ABB* arv);

#endif
