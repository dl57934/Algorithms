#include <stdio.h>

int arr[42] = {0, };

int main(){
	int N;
	int count = 0;
	for(int i = 0; i < 10; i++){
		scanf("%d", &N);
		arr[N%42]+=1;
	}

	for(int i = 0; i < 42; i++)
		if(arr[i] != 0)
			count+=1;
	printf("%d", count);
}