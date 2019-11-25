//
// Created by 2019202359 on 25/11/19.
//


#include <ctype.h>
#include "hashTable.h"

struct palavra {
    char *palavra;
    unsigned int frequencia;
    tPalavra* prox;
};

void IniciaHash (Hash tab) {
    for (int i = 0; i < NTAB; ++i) {
        tab[i] = NULL;
    }
}

int hash (char* s) {
    int total = 0;
    for (int i = 0; s[i]!='\0'; ++i) {
        total += s[i];
    }
    return (total % NTAB);
}

tPalavra* acessa(Hash tab, char *s) {
    tPalavra* p;
    int h = hash(s); /*!< funcao que maluca tudo */
    for (p = tab[h]; p!=NULL; p = p->prox){
        if (strcmp(s, p->palavra) == 0) {
            return p;
        }
    }

    p = (tPalavra*) malloc(sizeof(tPalavra));
    strcpy(p->palavra, s);
    p->frequencia = 0;
    p->prox = tab[h];
    tab[h] = p;
    return p;
}

int lePalavra(FILE *fp, char *s) {
    int i = 0;
    char c;

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c))
            break;
    }

    if (c == EOF){
        return 0;
    } else {
        s[i++] = c;
    }

    while ((i<NPAL-1) && (c = fgetc(fp))!=NULL && isalpha(c)){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int conta (Hash tab){
    int i;
    int total = 0;
    tPalavra* p;
    for (int i = 0; i < NTAB; ++i) {
        for (p = tab[i]; p != NULL; p = p->prox) {
            total++;
        }
    }
    return total;
}

tPalavra* criaVet (Hash tab, int n){
    int i, j = 0;
    tPalavra* p;
    tPalavra** vet = (tPalavra*)malloc(sizeof(tPalavra));
    for (int i = 0; i < NTAB; ++i) {
        for (p = tab[i]; p != NULL; p = p->prox) {
            vet[j++] = p;
        }
    }

    return vet;
}

int compara (const void* v1, const void* v2){
    tPalavra** p1 = (tPalavra**) v1;
    tPalavra** p2 = (tPalavra**) v2;

    if ((*p1)->frequencia > (*p2)->frequencia)
        return -1;
    else if ((*p1)->frequencia < (*p2)->frequencia)
        return 1;
    else
        return (strcmp((*p1)->palavra,(*p2)->palavra));
}

void imprime (Hash tab){
    int i;
    int n;

    tPalavra** vet;

    n = conta(tab);

    vet = criaVet(tab, n);

    qsort(vet, n, sizeof(tPalavra*), compara);

}