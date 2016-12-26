#include "stdafx.h"
#include <iostream>
#include <memory>

using namespace std;

void swa(void *ap, void *bp,int size);
int main() {
	char *a = "aaaaaa";
	cout << &a << endl;
	char *b = "bbbbbb";

	swa(&a, &b,sizeof(char *));
	cout << &a << endl;
	cout << a << endl;
	while (1);
}

void swa(void *ap, void *bp, int size) {
	char *buff;
	buff = (char *)malloc(size);

	memcpy(buff, ap,size);
	memcpy(ap, bp, size);
	memcpy(bp, buff, size);
}