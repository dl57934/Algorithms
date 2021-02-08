#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int dp[100002];

int main(){
	int N;
	scanf("%d", &N);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	vector <int> base;
	for(int i = 4; i <= N; i++){
		int mod = sqrt(i);
		if(sqrt(i)-mod == 0){
			dp[i] = 1;
			base.push_back(i);
		}
		else{
			dp[i] = dp[i-1] + 1;
			for(int num : base)
				dp[i] = min(dp[i], dp[num] + dp[i - num]);
		}
	}

	printf("%d", dp[N]);
}

// [1] = 1
// [2] = 2
// [3] = 3
// [4] = 1
// [5] = 2
// [6] = 3
// [7] = 4
// [8] = 2
// [9] = 1
// [10] = 2
// [11] = 3
// [12] = 4
// [13] = 2
// [14] = 3
// [15] = 4;
// [16] = 1;