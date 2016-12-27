#include "stdafx.h"
#include "Insearch.h"
using namespace std;
void test_swap() {
	char *a = "aaaaaa";
	char *b = "bbbbbb";
	swap(&a, &b, sizeof(char *));
	while (1);
}
void test_Isearch_Int() {
	int a[] = { 1,2,3,4,5,6,7,8 };
	int b = 3;
	int n = 8;
	int elemSize = sizeof(int);
	int *found = (int *)Isearch(&b, &a, n, elemSize, Int_Cmp);
	if (found == NULL) {
		cout << "Not in array" << endl;
	}
	else {
		cout << "In array" << endl;
	}
	while (1);
}
void test_Isearch_Char() {
	char *notes[] = { "Ab","F#","B","Gb","D" };
	char *fevourte = "Eb";
	cout << &fevourte << endl;
	char **found = (char **)Isearch(&fevourte, notes, 5, sizeof(char*), Str_Cmp);
	if (found == NULL) {
		cout << "Not in array" << endl;
	}
	else {
		cout << "In array" << endl;
	}
	while (1);
}
void swap(void *ap, void *bp, int size) {
	char *buff;
	buff = (char *)malloc(size);
	memcpy(buff, ap, size);
	memcpy(ap, bp, size);
	memcpy(bp, buff, size);
}
void *Isearch(void *key, void *base, int n, int elemSize, int(*cmpfn) (void *, void*)) {
	for (int i = 0; i < n; i++) {
		void *ElemAddr = (char *)base + i*elemSize;
		if (cmpfn(key, ElemAddr) == 0) {
			return ElemAddr;
		}
	}
	return NULL;
}
int Int_Cmp(void *emel1, void *emel2) {
	int *ap1 = static_cast<int *>(emel1);
	int *ap2 = static_cast<int *>(emel2);
	cout << *ap1 << endl;
	return (*ap1 == *ap2);
}
int
Str_Cmp(void *emel1, void *emel2) {
	const char *ap1 = *static_cast<char **>(emel1);
	const char *ap2 = *static_cast<char **>(emel2);
	return strcmp(ap1, ap2);;
}