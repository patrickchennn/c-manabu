#include <stdio.h>

int main(){
	int x = 5;
	printf("&x=%p\n",&x);
	int *p = &x;
	*p = 6;

	int **q = &p;
	int ***r = &q;
	printf("*p=%d\n", *p); // 6
	printf("*q=%p\n", *q); // `*p` which pointing to `&x`, so it contains address of `x`; `*p` -> `&x`
	printf("*(*q)=%d\n", *(*q)); // 6
	printf("*(*r)=%p\n", *(*r)); // `**q` -> `*p` -> `&x`
	printf(" *(*(*q))=%d\n", *(*(*r))); // 6


	printf("%b\n",*q == *(*r) == *(*(*r)));

	***r = 10;
	printf("x=%d\n",x);

}