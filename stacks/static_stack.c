#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE ((int)32768)

struct Stack{
  int top;
  int data[MAX_SIZE];
};

int init_stack(Stack *s)
{
    s->top = 0;
    //s->data = malloc(sizeof(int) * MAX_SIZE);
    if(s->data == NULL)
    {
        return -1;
    }
    return 0;
}


inline int size(Stack *s) {
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
    s->top++;
    s->data[s->top] = new;
  }
  return 0;
}

int Stack_pop(Stack *s) {
  if (Stack_empty(s) == 0)
    return -1;
  else {
    int val = s->data[s->top];
    s->top--;
    return val;
  }
}

int Stack_peek(Stack *s) {
  if (Stack_empty(s) == 0)
    return -1;
  else
    return s->data[s->top];
}

void Stack_print(Stack *s) {
  int i;
  for (i = 1; i <= s->top; i++)
    printf("%d ", s->data[i]);
  printf("\n");
}
