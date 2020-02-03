#include <cstdio>
#include <algorithm>

using namespace std;

long long int N, M;
long long divideBy5(long long num);
long long divideBy2(long long num);

int main(){
	scanf("%lld %lld", &N, &M);
	printf("%lld", min(divideBy5(N) - (divideBy5(M)+divideBy5(N-M)), divideBy2(N) - (divideBy2(M)+divideBy2(N-M))));
}


long long divideBy5(long long num){
	long long appendix=0;
	for(long long i = 5; i<=num; i*=5)
		appendix+=num/i;
	return appendix;
}

long long divideBy2(long long num){
	long long appendix=0;
	for(long long i = 2; i<=num; i*=2)
		appendix += num/i;
	return appendix;
}