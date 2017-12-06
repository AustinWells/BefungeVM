#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 32768
#define INIT_SIZE 1024

typedef struct Stack {
  int top;
  int *data;
  size_t capacity;

} Stack;


int init_stack(Stack *s)
{
    s->top = 0;
    s->capacity = INIT_SIZE;
    s->data = malloc(sizeof(int) * INIT_SIZE);
    if(s->data == NULL)
    {
        return -1;
    }
    return 0;
}

int Stack_expand(Stack *s)
{
    if(s->capacity * 2 < MAX_SIZE)
    {
        int *new_data = malloc(s->capacity * 2);
        if(new_data == NULL)
        {
            exit(1);
        }
        memcpy(new_data, s->data, s->capacity * sizeof(int));
        s->capacity *= 2;
        free(s->data);
        s->data = new_data;
        return 1;
    }
    else if(s->capacity == MAX_SIZE)
    {
        return 0;
    }
    else if(s->capacity * 2 > MAX_SIZE)
    {
        int *new_data = malloc(MAX_SIZE);
        if(new_data == NULL)
        {
            exit(1);
        }
        memcpy(new_data, s->data, s->capacity * sizeof(int));
        s->capacity = MAX_SIZE;
        free(s->data);
        s->data = new_data;
        return 1;
    }
    else
    {
        return 0;
    }

}

int Stack_shrink(Stack *s)
{
    if(s->top <= (s->capacity / 4))
    {
        int *new_data = malloc(s->capacity / 2);
        if(new_data == NULL)
        {
            exit(1);
        }
        memcpy(new_data, s->data, s->top * sizeof(int));
        s->capacity /= 2;
        free(s->data);
        s->data = new_data;
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}

int size(Stack *s) {
  return s->top;
}

int Stack_empty(Stack *s) {
  if (size(s) <= 0)
    return 0;
  else
    return 1;
}

int Stack_full(Stack *s) {
  if (size(s) == s->capacity)
    return Stack_expand(s);
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
    Stack_shrink(s);
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
