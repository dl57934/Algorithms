#include <cstdio>

#define Max(a, b) a < b? 1: 0

int getGSD(int A, int B);
int getLCM(int A, int B, int gsd);
void swap(int *A, int *B);

int main(){
	int T;
	int A, B;

	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		scanf("%d %d", &A, &B);
		if(Max(A, B))
			swap(&A, &B);
		printf("%d\n", getLCM(A, B, getGSD(A, B)));
	}
}

void swap(int *A, int *B){
	int temp = *A;
	*A = *B;
	*B = temp;
}

int getGSD(int A, int B){
	if(B == 0)
		return A;
	else 
		return getGSD(B, A%B);
}

int getLCM(int A, int B, int gsd){
	return (A*B)/gsd;
}