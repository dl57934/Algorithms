#include <cstdio>
#include <vector>

using namespace std;

vector <int> primeNumber;
void setPrimeNumber();
int check[4000002] = {0, };
int  twoPointer(int N);

int main(){
	int N;
	setPrimeNumber();
	scanf("%d", &N);
	printf("%d", twoPointer(N));
}

void setPrimeNumber(){
	

	for(int i = 2; i <= 4000000; i++){
		if(check[i] == 1) continue;
		for(int subnum = i+i; subnum <= 4000000; subnum+=i){
			check[subnum] = 1;
		}
	}

	for(int i = 2; i <= 4000000; i++)
		if(!check[i])
			primeNumber.push_back(i);
}

int  twoPointer(int N){
	int start = 0, desti = 0;
	int subnum = 0, count = 0;
	int size = primeNumber.size();
	while(desti < size){
		if(subnum < N){
			subnum+=primeNumber[desti];
			desti++;
		}else{
			subnum-=primeNumber[start];
			start++;
		}

		if(subnum == N) count++;
	}
	return count;
}