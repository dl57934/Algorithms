#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int maxDp[4], minDp[4];
int map[100002][5];

void solve();

int main(){
	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
		scanf("%d %d %d", &map[i][1], &map[i][2], &map[i][3]);
	
	solve();
}

int maxDp1 , maxDp2, maxDp3;
int minDp1 , minDp2, minDp3;

void solve(){
	for(int i = 1; i <= N; i++){
		
			maxDp1 = max(maxDp[1], maxDp[2]) + map[i][1];
			maxDp2 = max(maxDp[2], max(maxDp[1], maxDp[3])) + map[i][2];
			maxDp3 = max(maxDp[3], maxDp[2]) + map[i][3];
			
			minDp1 = min(minDp[1], minDp[2]) + map[i][1];
			
			minDp2 = min(minDp[2], min(minDp[1], minDp[3])) + map[i][2]; 
			
			minDp3 = min(minDp[3], minDp[2]) + map[i][3];

			maxDp[1] = maxDp1;
			maxDp[2] = maxDp2;
			maxDp[3] = maxDp3;

			minDp[1] = minDp1;
			minDp[2] = minDp2;
			minDp[3] = minDp3;
	}

	printf("%d %d", max(maxDp[1], max(maxDp[2], maxDp[3])), min(minDp[1], min(minDp[2], minDp[3])));
}