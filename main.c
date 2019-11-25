#include <stdio.h>
#include "hashTable.h"

int main( int argc, char** argv) {
    FILE *fp;
    Hash tab;
    char s[NPAL];

    if (argc != 2) {
        printf("Arquivo nao encontrado\n");
        return 0;
    }

    fp = fopen(argv[1], "rt");

    if (fp == NULL) {
        printf("Erro na abertura do Arquivo\n");
    }
    IniciaHash(tab);
    while (lePalavra(fp, s)){
        tPalavra* p = acessa(tab, s);

    }
}