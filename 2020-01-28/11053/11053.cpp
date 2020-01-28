#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int arr[1002];
int dp[1002];
int main(){
	scanf("%d", &N);
	
	for(int i =0; i < N; i++)
		scanf("%d", &arr[i]);

	for(int i = 0; i < N; i++){
		if(dp[i] == 0)dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j])
				if(dp[i] < dp[j]+1)
					dp[i] = dp[j]+1;
		}
	}
	printf("%d", *max_element(dp, dp+N));
}