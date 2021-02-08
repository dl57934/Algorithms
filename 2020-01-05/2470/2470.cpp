#include <cstdio>
#include <algorithm>
#include <stdlib.h>
using namespace std;

#define ll long long

int N;
ll num[1000002];

void twoPointer();

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%lld", &num[i]);

	sort(num, num + N);

	twoPointer();
}

void twoPointer(){
	int start = 0, end = N-1;
	ll resultStart = num[start], resultEnd = num[end];
	ll diff = num[start] + num[end];

	while(start < end){
		if(abs(num[start] + num[end]) < abs(diff)){
			resultStart = num[start], resultEnd = num[end];
			diff = num[start] + num[end];
		}

		if(num[start] + num[end] < 0){
			start++;
		}else if(num[start] + num[end] > 0){
			end--;
		}

		if(num[start] + num[end] == 0){
			printf("%lld %lld", num[start], num[end]);
			exit(0);
		}
	}

	printf("%lld %lld", resultStart, resultEnd);
}