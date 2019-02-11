#include <stdio.h>

int arr[1002] = {0,};
int getboxes(int N);


int main(){
	int n;
	scanf("%d", &n);
	int result = getboxes(n);
	printf("%d", result);
}

int getboxes(int N){
	if(N == 1)
		return 1;
	else if(N==2)
		return 2;
	else {
		if(arr[N] == 0)
			arr[N] = getboxes(N-1)%10007 + getboxes(N-2)%10007;
		return  arr[N]%10007;
	}
}