#include "stdafx.h"
#include"static.h"
#include<iostream>
#include<assert.h>
void
StaticNew(stack *s) {
	s->AllowLenth = 4;
	s->LogicalLen = 0;
	s->Elems  = (int *)malloc(4 * sizeof(int));
	assert(s->Elems != NULL);
}