#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 32768

typedef struct Node {
	int val;
	struct Node *next;
} Node;

struct Stack{
  int top;
  Node *data;
};

int init_stack(Stack *s)
{
    s->top = 0;
    s->data = malloc(sizeof(Node));
    if(s->data == NULL)
    {
        return -1;
    }
    return 0;
}


int size(Stack *s) {
  return s->top;
}

int Stack_empty(Stack *s) {
  if (size(s) < 0)
    return 0;
  else
    return 1;
}

int Stack_full(Stack *s) {
  if (size(s) == MAX_SIZE - 1)
    return 0;
  else
    return 1;
}

int Stack_push(Stack *s, int new) {
  if (Stack_full(s) == 0)
    return -1;
  else {
    Node *n = malloc(sizeof(Node));
    if(n == NULL){
		return -1;
    }
    n->val = new;
    n->next = s->data;
    s->data = n;
    s->top++;
  }
  return 0;
}

int Stack_pop(Stack *s) {
  if (Stack_empty(s) == 0)
    return -1;
  else {
    Node *n = s->data;
    s->data = s->data->next;
    int val = n->val;
    free(n);
    return val;
  }
}

int Stack_peek(Stack *s) {
  if (Stack_empty(s) == 0)
    return -1;
  else
    return s->data->val;
}

void Stack_print(Stack *s) {
  Node *curr;
  for (curr = s->data; curr != NULL; curr = curr->next)
    printf("%d ", curr->val);
  printf("\n");
}
