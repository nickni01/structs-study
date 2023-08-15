#include <stdio.h>
#include <stdlib.h>

/* Implement stack by using array */
struct Stack{
	int capability;
	int sp;
	int *data;
};
typedef struct Stack *slink;

slink create_stack(int capability)
{
	slink stack = malloc(sizeof(struct Stack));
	if (!stack) {
		return NULL;
    }

	stack->capability = capability;
	stack->sp = -1;
	stack->data = malloc(sizeof(int) * capability);
	return stack;
}

void free_stack(slink stack)
{
    if (!stack) {
        return;
    }

    free(stack->data);
    free(stack);
}

int empty(slink stack)
{
	return stack->sp == -1;
}

int full(slink stack)
{
	return stack->sp == (stack->capability - 1);
}

void push_stack(slink stack, int item)
{
	stack->data[++stack->sp]= item;
}

int pop_stack(slink stack) {
	if (empty(stack)) {
		return -1;
    }
	return stack->data[stack->sp--];
}

int main(){
	slink stack=create_stack(5);
	int data[]={1,2,3,4,5,6,7,8,9};
	int i=0;

    /* push stack */
    while (!full(stack)) {
		push_stack(stack,data[i++]);
    }

    /* pop stack */
	while (!empty(stack)) {
		printf("%d\n", pop_stack(stack));
    }

    /* push to the full */
	while ((i < 9) && (!full(stack))) {
		push_stack(stack, data[i++]);
    }

    /* pop stack */
    while(!empty(stack)) {
		printf("%d\n", pop_stack(stack));
    }

    free(stack);
}