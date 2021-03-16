#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int isPrime[4000005] = { 0, };
int primeNumber[4000005] = { 0, };

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 2; i <= 4000000; i++){
		if(isPrime[i] == 1) continue;
		for(int j = i + i; j <= 4000000; j+=i){
			isPrime[j] = 1;
		}
	}

	for(int i = 2; i <= 4000000; i++){
		if(isPrime[i] == 0)
			primeNumber[i] = i;
	}

	for(int i = N; i <= 4000000; i++){
		if(primeNumber[i] != 0){
			string original = to_string(primeNumber[i]);
			string reverseString =to_string(primeNumber[i]);
			reverse(reverseString.begin(), reverseString.end());
			if(original == reverseString){
				printf("%s\n", original.c_str());
				break;
			}
		}
	}

}