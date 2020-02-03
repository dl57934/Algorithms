#include <cstdio>
#include <algorithm>

int arr[100003];
int stack[100003];
long long answer=0;

int main(){
	int K;
	int index = 0;
	scanf("%d", &K);
	for(int i = 0; i < K; i++)
		scanf("%d", &arr[i]);

	for(int i = 0; i < K; i++){
		if(arr[i] == 0){
			stack[index] = 0;
			index-=1;
		}
		else {
			stack[index] = arr[i];
			index+=1;
		}
	}

	for(int i = 0; i < index; i++)
		answer+=stack[i];
	
	printf("%lld", answer);
}