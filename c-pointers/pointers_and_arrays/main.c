#include <stdio.h>

int main(){
	int A[] = {2,4,1,23,4,5};

	for(int i=0; i<sizeof(A)/sizeof(int); i++){
		// two ways for accessing address in array
		printf("A+%d=%p\n", i, A+i);
		printf("&A[%d]=%p\n", i, &A[i]);

		// also two ways for accessing the values of array
		printf("A[%d]=%d\n", i, A[i]);
		printf("*(A+%d)=%d\n\n", i, *(A+i));
	}
}