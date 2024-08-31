// C program to use restrict keyword.
#include <stdio.h>
 
// Note that the purpose of restrict is to
// show only syntax. It doesn't change anything
// in output (or logic). It is just a way for
// programmer to tell compiler about an
// optimization
void use(int* a, int* restrict c){
    *a += *c;
}
 
int main(void){
    int a = 50, c = 70;
    use(&a, &c);
    printf("%d %d\n", a, c);
    return 0;
}

// https://www.geeksforgeeks.org/restrict-keyword-c/