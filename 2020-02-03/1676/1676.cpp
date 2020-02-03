#include <cstdio>
#include <algorithm>

using namespace std;

int N;
long long fiveCount = 0;
long long doubleCount = 0;
int main(){
	scanf("%d", &N);
	for(int i = 5; i <= N; i*=5)
		fiveCount += N/i;

	for(int i = 2; i <= N; i*=2)
		doubleCount += N/i;

	printf("%lld", min(fiveCount, doubleCount));
}