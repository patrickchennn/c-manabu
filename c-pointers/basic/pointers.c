#include <stdio.h>

int main(){

	int a = 10;

	printf("a=%d\n", a);

	// this is the address of `int a`
	printf("&a=%p\n", &a);

	int *p;
	p = &a;
	// access the value of `int a` through pointer `int *p`
	printf("*p=%d\n", *p);

	// pointing `int *p` to address of `int a`
	printf("p=%p\n", p);

	// the address of pointer `p` it self
	printf("&p=%p\n", &p);

	// dereferencing, in this case it means using pointer `p` to change the value of `a`
	*p = 12;
	printf("*p=%d\n", *p);

}