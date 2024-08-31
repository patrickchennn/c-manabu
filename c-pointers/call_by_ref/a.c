#include <stdio.h>

// call by value
void Inc(int b){
	b = b+1;
	printf("&b in Inc()=%p\n", &b);
}

// call by reference
void Inc2(int *a){
	*a = *a+1;
	printf("&a in Inc2()=%p\n", a);
}

int main(){
	int a;
	a = 10;
	printf("&a in main()=%p\n", &a);
	Inc2(&a);
	printf("a=%d\n", a);

	int b;
	b = 10;
	printf("&b in main()=%p\n", &b);
	Inc(b);
	printf("b=%d\n", b);
}