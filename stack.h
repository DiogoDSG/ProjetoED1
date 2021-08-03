#include "stdio.h"
#include "stdlib.h"

/* Estrutura que representa um ponto */
typedef struct _point {
    int x;
    int y;
} Point;

/* Estrutura que representa uma pilha usando lista encadeada */
typedef struct _stack {
    Point coord;
    struct _stack* next;
}Stack;

/* Cria uma nova pilha */
Stack* create_stack();

/* Insere um novo elemento no topo da pilha */
Stack* push(Stack* s, Point p);

/* Remove um elemento no topo da pilha */
Stack* pop(Stack* s);

/* Verifica se a pilha esta vazia */
int empty_stack(Stack* s);

/* Desaloca a pilha */
void destroy_stack(Stack* s);

/* Preenche a pilha */
Stack* fill(Stack* s); 