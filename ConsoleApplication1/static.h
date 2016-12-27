#pragma once
typedef struct {
	int *Elems;
	int LogicalLen;
	int AllowLenth;
}stack_int;
typedef struct {
	void *elems;
	int ElemSize;
	int LogicalSize;
	int AllowSize;

}stack;
void
StackNew(stack *s, int ElemSize);           //ͨ��ջ�½�
void
StackPush(stack *s, void *ElemAddr);        //ͨ��ջpush
void 
StackNew_int(stack_int *s);                 //intջ�½�
void 
StackDispose(stack_int *s);
void
StackPush_int(stack_int *s, int value);
int
StackPop_int(stack_int *s);
