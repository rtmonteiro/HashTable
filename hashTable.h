//
// Created by 2019202359 on 25/11/19.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NTAB 127
#define NPAL 64

typedef struct palavra tPalavra;
typedef tPalavra* Hash[NTAB];

void IniciaHash (Hash tab);
int hash (char* s);
tPalavra* acessa (Hash tab, char* s);
int lePalavra (FILE* fp, char* s);

#endif //HASHTABLE_HASHTABLE_H
