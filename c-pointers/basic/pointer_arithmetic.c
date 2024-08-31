#include <stdio.h>

int main(){

	int a = 10;
	int *p;
	p = &a;

	// pointing `int *p` to address of `int a`
	printf("p=%p\n", p);
	printf("sizeof(int)=%d\n", sizeof(int));
	printf("p+1=%p\n", p+1);
}