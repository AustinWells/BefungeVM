#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 32768

typedef struct Node{
    int val;
    struct Node* next;
}Node;

struct Stack{
    Node *data;
};

int init_stack(Stack *s)
{
    s->data = NULL;
    return 0;
}


int size(Stack *s){
    int i = 0;
    for(Node *curr = s->data; curr != NULL; i++){}
    return i;
}

int Stack_empty(Stack *s) {
    if (s->data == NULL){
        return 0;
    }
    return 1;
}

//there is no max size in a linked list technically
int Stack_full(Stack *s) {
    return 1;
}


int Stack_push(Stack *s, int new) {

    Node *new_data = malloc(sizeof(Node));
    if(new_data == NULL) {
        return -1;
    }
    else {
        new_data->val = new;
        new_data->next = NULL;
        Node *curr = s->data;
        if(curr != NULL){
            for(;curr->next != NULL; curr = curr->next){}
            curr->next = new_data;
        }
        else{
            s->data = new_data;
        }
        return 0;
    }
}

int Stack_pop(Stack *s) {
    if (Stack_empty(s) == 0){
        return -1;
    }
    else {
        Node *curr = s->data;
        if(curr->next == NULL) {
            int val = curr->val;
            s->data = NULL;
            return val;
        }
        else{
            Node *curr2;
            for(curr2 = curr->next; curr2 -> next != NULL; curr2 = curr2->next){
                curr = curr2;
            }
            curr->next = NULL;
            int val = curr2->val;
            free(curr2);
            return val;
        }
    }
}

int Stack_peek(Stack *s) {
    if (Stack_empty(s) == 0)
    return -1;
    else {
        Node *curr = s->data;
        for(;curr->next != NULL; curr = curr->next){}
        return curr->val;
    }
}

void Stack_print(Stack *s) {}
