#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int num[202], dp[202];

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &num[i]);
		dp[i] = 1;
	}

	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			if(num[i] < num[j] && dp[i] + 1 > dp[j])
				dp[j] = dp[i] + 1;
		}
	}

	printf("%d", N - *max_element(dp, dp + N)); 
}