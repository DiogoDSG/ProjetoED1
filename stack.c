#include "stack.h"

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
    Stack* aux = s;

    if(s != NULL){    
        s = s->next;
    }

    return aux;
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
    for(int i = 0; i < 400; i++){
        coord.x = 100 + i;
        coord.y = 100 + i;
        s = push(s, coord);
    }
}