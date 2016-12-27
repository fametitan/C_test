#include "stdafx.h"
#include"static.h"
#include<iostream>
#include<assert.h>

void 
StackNew(stack *s, int ElemSize, void(*freefn)(void *)) {

	assert(ElemSize > 0);

	s->ElemSize = ElemSize;

	s->AllowSize = 4;

	s->LogicalSize = 0;

	s->elems = malloc(s->AllowSize*s->ElemSize);

	s->freefn = freefn;

	assert(s->elems != NULL);

}

void
StackPush(stack *s, void *ElemAddr) {

	assert(ElemAddr != NULL);

	if (s->ElemSize == s->LogicalSize) {

		s->AllowSize *= 2;

		s->elems = (void *)realloc(s->elems, s->AllowSize*s->ElemSize);

		assert(s->elems != NULL);

	}

	void *target = (char *)s->elems + s->ElemSize*s->LogicalSize;

	memcpy(target, ElemAddr, s->ElemSize);

	s->LogicalSize++;

}

void
StackPop(stack *s, void *ElemAddr) {

	void *source = (char *)s->elems + (s->LogicalSize-1)*s->ElemSize;

	memcpy(ElemAddr, source, s->ElemSize);

	s->LogicalSize--;

}
void
StackNew_int(stack_int *s) {

	s->AllowLenth = 4;

	s->LogicalLen = 0;

	s->Elems  = (int *)malloc(4 * sizeof(int));

	assert(s->Elems != NULL);

}

void
StackDispose(stack *s) {
	if (s->freefn != NULL) {
		for (int i = 0; i < s->LogicalSize; i++) {
			s->freefn((char *)s->elems + i*s->ElemSize);
		}
	}

	free(s->elems);
	assert(s->elems == NULL);

}

void
StackPush_int(stack_int *s, int value) {

	if (s->LogicalLen == s->AllowLenth) {

		s->AllowLenth *= 2;

		s->Elems = (int *)realloc(s->Elems, s->AllowLenth*sizeof(int));

		assert(s->Elems != NULL);

	}

	s->Elems[s->LogicalLen] = value;

	s->LogicalLen++;

}

int
StackPop_int(stack_int *s) {

	assert(s->LogicalLen > 0);

	s->LogicalLen--;

	return s->Elems[s->LogicalLen];

}

void Test_Stack() {
	const char *friends[] = { "Aa","Bb","Cc" };
	stack StrStack;
	StackNew(&StrStack, sizeof(char *),StringFree);
	for (int i = 0; i < 3; i++) {
		char *copy = strdup(friends[i]);
		StackPush(&StrStack, &copy);
	}
	char *name;
	for (int i = 0; i < 3; i++) {
		StackPop(&StrStack, &name);
		free(name);
	}
	StackDispose(&StrStack);

}

void StringFree(void *elem) {
	free(*(char **)elem);
}

void
rotate(void *front, void *middle, void *back) {
	int FrontSize = (char *)middle - (char *)front;
	int BackSize = (char *)back - (char *)middle;
	char *buffer;
	buffer = (char *)malloc(FrontSize);
	memcpy(buffer, front, FrontSize);
	memmove(front, middle, BackSize);
	memcpy((char *)back - FrontSize, buffer, FrontSize);
}

