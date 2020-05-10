#include <cstdio>
#include <algorithm>

using namespace std;

void input();
long long S, N;
long long arr[100003];

long long getSumSize();

int main(){
	input();
	printf("%lld", getSumSize());
}

void input(){
	scanf("%lld %lld", &N, &S);
	for(int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);
}

long long getSumSize(){
	long long start = 0, end = 0;
	long long result = 987654321, sum = 0;

	while(end <= N){
		if(sum < S){
			sum += arr[end];
			end++;
		}else if(sum >= S){
			result = min(result, (end - start));
			sum -= arr[start];
			start++;
		}
	}
	if(result == 987654321)
		return 0;
	else 
		return result;
}