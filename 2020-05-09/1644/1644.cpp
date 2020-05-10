#include <vector>
#include <cstdio>
#include <math.h>

using namespace std;

int N;
vector <int> isPrime(4000002, 1);
vector <int> primeNum;
void getPrime();
int getSum();

int main(){
	scanf("%d", &N);
	getPrime();
	printf("%d", getSum());
}

void getPrime(){
	for(int number = 2; number <= 4000000; number++){
		if(isPrime[number] == 0) continue;
		for(int num = number+ number; num <= 4000000; num+=number)
			isPrime[num] = 0;
	}
	for(int number = 2; number <= 4000000; number++)
		if(isPrime[number] != 0)
			primeNum.push_back(number);

}


int getSum(){
	int start = 0, end = 0;
	int sum = 0, count = 0;
	while(end <= primeNum.size()){
		if(sum < N){
			sum+=primeNum[end];
			end++;
		}else if(sum >= N){
			sum-=primeNum[start];
			start++;
		}

		if(sum == N)
			count += 1;
	}
	return count;
}


