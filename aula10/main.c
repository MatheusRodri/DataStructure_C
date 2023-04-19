#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct aux {
TIPOCHAVE chave;
struct aux *esq;
struct aux *dir;
int h; //essencial para calcular o fator de balanceamento
} NO, *PONT;

PONT criarNo(TIPOCHAVE ch) {
    PONT novoNo =(PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    novoNo->h = 0;
    return novoNo;
}
PONT inicializar() {
    return NULL;
}


int altura (PONT raiz) {
    return (!raiz) ? -1: raiz->h;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

PONT rotacaoDireita(PONT r) {
    PONT aux;
    aux = r->esq;
    r->esq = aux->dir;
    aux->dir = r;
    r->h = max(altura(r->dir), altura(r->esq)) + 1;
    aux->h = max(altura(aux->esq), r->h) + 1;
    return aux;
}

PONT rotacaoEsquerda(PONT r) {
    PONT aux;
    aux = r->dir;
    r->dir = aux->esq;
    aux->esq = r;
    r->h = max(altura(r->dir), altura(r->esq)) + 1;
    aux->h = max(altura(aux->dir), r->h) + 1;
    return aux;
}

PONT rotacaoEsquerdaDireita(PONT r) {
    r->esq = rotacaoEsquerda(r->esq);
    return rotacaoDireita(r);
}

PONT rotacaoDireitaEsquerda(PONT r) {
    r->dir = rotacaoDireita(r->dir);
    return rotacaoEsquerda(r);
}

PONT insere(PONT raiz, TIPOCHAVE ch) {
    if (!raiz) return(criarNo(ch));
    if (ch < raiz->chave) {
        raiz->esq = insere(raiz->esq, ch);
        if ((altura(raiz->esq) - altura(raiz->dir)) == 2)
            if (ch < raiz->esq->chave)
                raiz = rotacaoDireita(raiz);
            else
                raiz = rotacaoEsquerdaDireita(raiz);
    }
    else
    if (ch > raiz->chave) {
        raiz->dir = insere(raiz->dir, ch);
        if ((altura(raiz->esq) - altura(raiz->dir)) == -2)
            if (ch > raiz->dir->chave)
                raiz = rotacaoEsquerda(raiz);
            else
                raiz = rotacaoDireitaEsquerda(raiz);
    }
    raiz->h = max(altura(raiz->esq), altura(raiz->dir))+1;
    return raiz;
}

int verificaAVL(NO* no){
    if (no == NULL) {
        return 1;
    }
    int altura_esquerda = altura(no->esq);
    int altura_direira = altura(no->dir);
    int balanco = altura_esquerda - altura_direira;
    if (balanco < -1 || balanco > 1) {
        return 0;
    }
    return verificaAVL(no->esq) && verificaAVL(no->dir);
}

int main(){
    PONT p = inicializar();
    PONT no = criarNo(50);



    return 0;
}