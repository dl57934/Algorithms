#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct powerLine{
	int left;
	int right;
}powerLine;

powerLine power[103];
int dp[103];

int N;

bool comp(powerLine power1, powerLine power2){
	return power1.left < power2.left;
}

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d %d", &power[i].left, &power[i].right);
	
	sort(power, power+N, comp);

	for(int i = 0; i < N; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(power[i].right > power[j].right && dp[i] < dp[j]+1)
				dp[i] = dp[j] + 1;
		}
	}

	printf("%d", N-*max_element(dp, dp+N));
}