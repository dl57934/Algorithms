#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int arr[1002];
int dp[2][1003];

int main(){
	int index = 0;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	for(int i = 0; i < N; i++){
		dp[0][i] = 1;
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j] && dp[0][i] < dp[0][j] + 1)
				dp[0][i] = dp[0][j] + 1;
		}
	}

	for(int i = N-1; i >= 0; i--){
		dp[1][i] = 1;
		for(int j = N-1; j >= i; j--){
			if(arr[i] > arr[j] && dp[1][i] < dp[1][j] + 1 )
				dp[1][i] = dp[1][j] + 1;
		}	
	}

	int answer = 0;

	for(int i = 0; i < N; i++)
		if(answer < dp[0][i] + dp[1][i]-1)
			answer = dp[0][i] + dp[1][i]-1;
	
	printf("%d", answer);
}