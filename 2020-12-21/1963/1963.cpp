#include <cstdio>
#include <queue>
#include <string>
using namespace std;

int input, target, T;
int isPrime[10000];
void astora();
void bfs();

int main(){
	scanf("%d", &T);
	astora();
	for(int i = 0; i < T; i++){
		scanf("%d %d", &input, &target);
		bfs();
	}
}

void astora(){
	for(int i = 2 ; i <= 9999; i++){
		if(isPrime[i] == 1) continue;
		for(int j = i + i; j <= 9999; j+=i){
			isPrime[j] = 1;
		}
	}
}

void bfs(){
	queue<pair<int, int> > qu;
	qu.push(make_pair(input, 0));
	int isVisited[10000] = {0, };
	while(!qu.empty()){
		pair<int, int> now = qu.front();
		int nowPrime = now.first, count = now.second;
		isVisited[nowPrime] = 1;

		if(nowPrime == target){
			printf("%d\n", count);
			return ;
		}
		qu.pop();
		for(int i = 0; i < 4; i++){
			int num = 0;
			if(i == 0)
				num = 1;
			for(int inputNum = num; inputNum <= 9; inputNum++){
				string nowPrimeString = to_string(nowPrime);
				nowPrimeString[i] = inputNum + '0';
				int changePrime = stoi(nowPrimeString);
				// printf("%d %d\n", changePrime, isPrime[changePrime]);
				if(isPrime[changePrime] == 0 && isVisited[changePrime] == 0){
					qu.push(make_pair(changePrime, count+1));	
				}
			}
		}
	}

	printf("Impossible\n");
}