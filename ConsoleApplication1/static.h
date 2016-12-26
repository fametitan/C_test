#pragma once
typedef struct {
	int *Elems;
	int LogicalLen;
	int AllowLenth;
}stack;
void 
StackNew(stack *s);
void 
StackDispose(stack *s);
void
StackPush(stack *s, int value);
void
StackPop(stack *s);