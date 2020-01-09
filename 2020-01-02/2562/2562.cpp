#include <stdio.h>

int indexCheck[12];
int arr[102] = {0,};


int main(){
	int N = 0;
	for(int i = 0; i < 9; i++){
		scanf("%d", &N);
		arr[N] += 1;
		indexCheck[i] = N;
	}

	for(int i=100; i >=0; i--)
		if(arr[i]!=0){
			printf("%d\n", i);
			N = i;
			break;
		}

	for(int i = 0; i < 9; i++){
		if( N == indexCheck[i])
			printf("%d", i+1);
	}
}