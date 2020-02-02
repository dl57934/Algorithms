#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int arr[1003];
int dp[1003];

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for(int i = 0; i < N; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j] && dp[i] < dp[j]+1)
				dp[i] = dp[j]+1;
		}
	}

	printf("%d", *max_element(dp, dp+N));
}