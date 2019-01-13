#include <stdio.h>
#include <string.h>

int arr[46]= {0,};
int zeroArr[46] = {1, 0};
int oneArr[46] = {0, 1};

int fibo(int n){
	if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }else{
    	if(arr[n] == 0){
    		arr[n] = fibo(n-1) + fibo(n-2);
    		zeroArr[n] = zeroArr[n-1] + zeroArr[n-2];
    		oneArr[n] = oneArr[n-1] + oneArr[n-2];
    	}
    	return arr[n];
    }
}

int main(T){
	int N;
	scanf("%d", &T);
	for(int i =0; i < T; i++){
		scanf("%d", &N);
		fibo(N);
		printf("%d %d\n", zeroArr[N], oneArr[N]);
	}
}