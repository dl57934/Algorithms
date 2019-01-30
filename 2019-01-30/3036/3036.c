#include <stdio.h>

int arr[1003];

int getGcd(int big, int small);
int isBig(int origin, int compare);

int main(){
	int N;
	scanf("%d", &N);
	int gcd = 0;
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		if(i > 0){
			if(isBig(arr[0], arr[i]))
				gcd = getGcd(arr[0], arr[i]);
			else
				gcd = getGcd(arr[i], arr[0]);
			printf("%d/%d\n",arr[0]/gcd, arr[i]/gcd);
			
		}
	}



}
int isBig(int origin, int compare){
	return origin > compare;
}

int getGcd(int big, int small){
	if(small == 0)
		return big;
	else 
		return getGcd(small, big%small);
}