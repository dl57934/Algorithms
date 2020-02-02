#include <stdio.h>

int  testCase;

long long arr[102];
int numbers = 0;
int main(){
	scanf("%d", &testCase);

	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	for(int i = 0; i < testCase; i++){
		scanf("%d", &numbers);

		for(int j = 3; j < numbers; j++)
			arr[j] = arr[j-3] + arr[j-2];
		

		printf("%lld\n", arr[numbers-1]);
	}
}