#include <stdio.h>
#include <stdlib.h>

#ifndef DEF
#define DEF

typedef struct nodo_t
{
    int dato;
    struct nodo_t *left;
    struct nodo_t *right;
} nodo_t;

#endif