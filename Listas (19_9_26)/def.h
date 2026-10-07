#include <stdio.h>
#include <stdlib.h>

#ifndef DEF
#define DEF

typedef struct nodo_t
{
    int dato;
    struct nodo_t *next;
} nodo_t;

typedef struct dnodo_t
{
    int dato;
    struct dnodo_t *next;
    struct dnodo_t *prev;
} dnodo_t;

#endif