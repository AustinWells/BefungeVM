typedef struct Stack Stack;

//jenkins test

int init_stack(Stack *s);
int size(Stack *s);
int Stack_empty(Stack *s);
int Stack_full(Stack *s);
int Stack_push(Stack *s, int new);
int Stack_pop(Stack *s);
int Stack_peek(Stack *s);
void Stack_print(Stack *s);
