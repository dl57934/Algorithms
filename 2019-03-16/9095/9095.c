#include <stdio.h>

int arr[15] = {};



int getMethods(int testCase);

int main(){
	int T, testCase;
	scanf("%d", &T);
	arr[1] = 1;
arr[2] = 2;
arr[3] = 4;
	for(int i = 0; i < T; i++){
		scanf("%d", &testCase);
		printf("%d\n", getMethods(testCase));
	}
}

int getMethods(int testCase){
	if(testCase == 1)
		return arr[1];
	else if(testCase == 2)
		return arr[2];
	else if(testCase == 3)
		return arr[3];
	if(arr[testCase] == 0)
		arr[testCase] = getMethods(testCase-1) + getMethods(testCase-2) + getMethods(testCase-3);
	return arr[testCase];
}