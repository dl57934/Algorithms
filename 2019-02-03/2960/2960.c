#include <stdio.h>
#include <math.h>

int arr[1002] = {0, };
int isPrime(int N);

int main(){
	int N, K;
	int primenum = 0, count = 0, result = 0;
	scanf("%d %d", &N, &K);
	for(int i = 2; i <= N; i++){
		if(isPrime(i)){
			primenum = i;
			while(primenum <= N){
				if (arr[primenum] == 0){
					count+=1;
					arr[primenum]=1;
					if(K == count){
						result=primenum;
						printf("%d", result);
						return 0;
					}
				}
				primenum+=i;
			}
		}	
	}
}

int isPrime(int N){
	for(int i = 2; i <=sqrt(N); i++){
		if(N%i==0)
			return 0;
	}
	return 1;
}