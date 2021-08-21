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

void print_stack(Stack* s);


typedef struct _list {
	Point p;
	struct _list* next;
} List;

List* create_list();

void free_list(List* q);

List* enqueue(List* q, Point elem);

List* dequeue(List* q);

void print_queue(List* q);

List* create_random_queue(int n);

List* remover(List* q, Point elem);

int isInList(List* l, Point p);