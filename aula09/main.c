#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX 50
typedef int bool;
typedef int TIPOCHAVE;
typedef struct aux {
    TIPOCHAVE chave;
    struct aux *esq, *dir;
} NO;
typedef NO *PONT;
PONT inicializar() { return NULL; }

PONT insere(PONT raiz, PONT no) {
    if (raiz == NULL)
        return no;
    if (no->chave <= raiz->chave)
        raiz->esq = insere(raiz->esq, no);
    else
        raiz->dir = insere(raiz->dir, no);
    return (raiz);
}
PONT criarNovoNo(TIPOCHAVE ch) {
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return (novoNo);
}
void imprimirArvore(PONT raiz) {
    printf("(");
    if (raiz != NULL) {
        printf(" %i ", raiz->chave);
        imprimirArvore(raiz->esq);
        imprimirArvore(raiz->dir);
    }
    printf(")");
}

int altura(PONT raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
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

int main() {
    PONT r = inicializar();
    PONT no = criarNovoNo(50);
    r = insere(r, no);
    no = criarNovoNo(40);
    r = insere(r, no);
    no = criarNovoNo(35);
    r = insere(r, no);
    no = criarNovoNo(45);
    r = insere(r, no);
    no = criarNovoNo(60);
    r = insere(r, no);
    no = criarNovoNo(55);
    r = insere(r, no);
    no = criarNovoNo(65);
    r = insere(r, no);


    imprimirArvore(r);
    int arvoreAltura = altura(r);
    printf("altura: %i", arvoreAltura);

    if(verificaAVL(r)){
        printf("Arvore AVL");
    }else{
        printf("Não AVL");
    }

    return 0;
}