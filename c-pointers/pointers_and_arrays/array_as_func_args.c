#include <stdio.h>

int SumElem(int A[], int n){
	int s=0;
	for(int i=0; i<n; i++){
		s+=A[i];
	}
	return s;
}

int SumElem2(int *A, int n){
	int s=0;
	for(int i=0; i<n; i++){
		s+=A[i];
	}
	return s;
}

int main(){
	int A[] = {1, 3, 5, 7};
	int n = sizeof(A)/sizeof(A[0]);

	printf("sizeof(A)=%ld; sizeof(A[0])=%ld\n", sizeof(A), sizeof(A[0]));

	// int t = SumElem(A, n);
	int t = SumElem2(A, n);
	printf("%d\n", t);
}
