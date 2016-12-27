#pragma once
#include "stdafx.h"
#include<iostream>
using namespace std;
void
test_swap();
void
test_Isearch_Int();
void
test_Isearch_Char();
void
*Isearch(void *key, void *base, int n, int elemSize, int(*cmpfn) (void *, void*));
void
swap(void *ap, void *bp, int size);
int
Int_Cmp(void *emel1, void *emel2);
int
Str_Cmp(void *emel1, void *emel2);
