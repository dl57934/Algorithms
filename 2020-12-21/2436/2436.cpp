#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

long long minNumber = INT_MAX;
pair<long long, long long> ans;

int isGcd(int a, int b);

int main(){
	long long A, B;
	scanf("%lld %lld", &A, &B);
	long long num = A;
	long long target = A * B;
	while(1){
		long long secondNum = target / num;
		if(num > secondNum){
			break;
		}else if(num + secondNum < minNumber && isGcd(num, secondNum)  == A && (num * secondNum)/A == B){
			minNumber = num + secondNum;
			ans.first = num;
			ans.second = secondNum;
		}
		num+=A;
	}

	printf("%lld %lld", ans.first, ans.second);
}

int isGcd(int a, int b){
	while(1){
		if(b == 0)
			return a;
		return isGcd(b, a%b);
	}
}