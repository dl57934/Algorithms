#include <cstdio>
#include <algorithm>
#define ll long long 

using namespace std;

ll INF = 987654321;
ll N, S;
ll arr[100002];
ll getRange();

int main(){
	
	scanf("%lld %lld", &N, &S);

	if(S == 0){
		printf("0");
		return 0;
	}

	for(int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);

	if(getRange()== INF)
		printf("0");
	else
		printf("%lld", getRange());
}

ll getRange(){
	ll start = 0, end = 0;
	ll minRange = 987654321, sum = 0;

	while(end <= N){
		if(sum < S){
			sum += arr[end];
			end++;
		}else if(sum >= S){
			sum -= arr[start];
			start++;
		}

		if(sum >= S) {
			minRange = min(minRange, (end-start));
		}
	}

	return minRange;
}