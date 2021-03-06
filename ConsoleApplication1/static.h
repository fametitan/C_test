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
	void(*freefn)(void *);

}stack;
void
StackNew(stack *s, int ElemSize);           //通用栈新建
void
StackPush(stack *s, void *ElemAddr);        //通用栈push
void 
StackNew_int(stack_int *s);                 //int栈新建
void 
StackDispose(stack_int *s);
void
StackPush_int(stack_int *s, int value);
int
StackPop_int(stack_int *s);
void
Test_Stack();
void
StringFree(void *elem);


void 
rotate(void *front, void *middle, void *back);   //移动堆的存放位置，让以front开头移动到以back结尾