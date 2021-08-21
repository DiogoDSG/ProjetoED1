#include "estruturas.h"

//____________________________________________________________________________________________
Stack* create_stack(){
    return NULL;
}

//____________________________________________________________________________________________
Stack* push(Stack* s, Point p){
    Stack* aux = (Stack*)malloc(sizeof(Stack));
    aux->coord = p;
    aux->next = (s == NULL) ? NULL : s;
    return aux;
}

//____________________________________________________________________________________________
Stack* pop(Stack* s){
    if (s != NULL) {
        s = s->next;
    }

    return s;
}

//____________________________________________________________________________________________
int empty_stack(Stack* s){
    return (s == NULL) ? 1 : 0;
}

//____________________________________________________________________________________________
void destroy_stack(Stack* s){
    while (s != NULL) {
        Stack* aux = s->next;
        free(s);
        s = aux;
    }
}

//____________________________________________________________________________________________
Stack* fill(Stack* s){
    Point coord;
    for(int i = 0; i < 10; i++){
        coord.x = 2 + i;
        coord.y = 2;
        s = push(s, coord);
    }
}

void print_stack(Stack* s){
    int i = 0;
    while (s != NULL && i++ < 8) {
        Stack* aux = s->next;
        printf("%d : %d\n", s->coord.x, s->coord.y);
        s = aux;
    }
}


/*Função para criar uma fila vazia (não criar nenhum nó, só devolver NULL)!*/
List* create_list() {
    return NULL;
}

/*Função para liberar uma fila nó por nó!*/
void free_List(List* q) {
    while (q != NULL)
    {
        List* aux = q;
        q = q->next;
        free(aux);
    }
}

/*Função para enfileirar um elemento (inserir na cauda da lista encadeada)!*/
List* enqueue(List* q, Point elem) {
    List* novo = (List*)malloc(sizeof(List));
    novo->p = elem;
    novo->next = q;
    return novo;
}

/*Função para desenfileirar um elemento (remover da cabeça da lista encadeada)!*/
List* dequeue(List* q) {
    List* paux = q;
    List* anterior = NULL;

    if (paux != NULL) {
        while (paux->next != NULL) {
            anterior = paux;
            paux = paux->next;
        }
    }
    else {
        return NULL;
    }

    if (anterior == NULL)
        q = NULL;
    else
        anterior->next = NULL;

    return paux;

}

/* função que imprime todos os elementos da lista encadeada */
void print_queue(List* q)
{
    int i = 0;
    for (List* aux = q; aux != NULL && (i < 5); aux = aux->next, i++){
        Point p = aux->p;
        printf("%d : %d\n", p.x, p.y);
    }
}

/* cria uma com n elementos */
List* create_random_queue(int n) {
    List* aux = create_list();

    // Preenche até o elemento n
    for (int i = n; i > 0; i--){
        Point p;
        p.x = i;
        p.y = i;
        aux = enqueue(aux, p);
    }

    return aux;
}

/* Remove um elemento da fila */
List* remover(List* q, Point elem) {
    List* pAnterior = NULL;
    List* pAtual = q;
    while (pAtual != NULL && pAtual->p.x != elem.x && pAtual->p.y != elem.y) {
        pAnterior = pAtual;
        pAtual = pAtual->next;
    }

    if (pAtual == NULL) {
        return NULL;
    }
    else if (pAnterior == NULL) {
        return q->next;
    }
    else {
        pAnterior->next = pAtual->next;
        return q;
    }
}

int isInList(List* l, Point p){
    List* pAnterior = NULL;
    List* pAtual = l;
    while (pAtual != NULL) {
        if(pAtual->p.x == p.x && pAtual->p.y == p.y){
            return 1;
        }

        pAnterior = pAtual;
        pAtual = pAtual->next;
    }

    return 0;
}