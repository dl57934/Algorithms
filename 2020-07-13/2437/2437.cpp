#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long

ll arr[1002];
int N;
void input();

int main(){
	input();
	ll target = 1;
	for(int i = 0; i < N; i++){
		if(target < arr[i]){
			printf("%lld", target);
			return 0;
		}
		target+=arr[i];
	}

	printf("%lld", target);
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr+N);
}