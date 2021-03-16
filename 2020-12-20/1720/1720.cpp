#include <cstdio>

int arr[1003];

int main(){
	int n;
	arr[0] = 1, arr[1] = 1;
	scanf("%d", &n);

	for(int i = 2; i <= n; i++){
		arr[i] = arr[i-2]*2 + arr[i-1];
	}

	if(n % 2 == 0){
		printf("%d", (arr[n] + arr[n/2 + 1])/2);
	}else{
		printf("%d", (arr[n] + arr[(n-1)/2])/2);
	}
}