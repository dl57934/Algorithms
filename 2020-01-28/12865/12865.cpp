#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector <pair<int, int> > bag(103);
int calcul[102][100002];

int N, K;

void opt();

int main(){
	scanf("%d %d", &N, &K);
	bag[0].first=0; 
	bag[0].second=0;
	for(int i = 1; i <= N; i++)
		scanf("%d %d", &bag[i].first, &bag[i].second); // first 무게, second 가치
 	opt();

 	for(int i = 0 ; i <= N;  i++){
 		for(int j = 0; j <= K; j++){
 			printf("%d ", calcul[i][j]);
 		}
 		printf("\n");
 	}
 	// printf("%d", calcul[N][K]);
}


void opt(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			if( bag[i].first > j)
				calcul[i][j] = calcul[i-1][j];
			else{
				int weight = bag[i].first;
				calcul[i][j] = max(bag[i].second + calcul[i-1][j - weight] ,calcul[i-1][j]);
			}
		}
	}
}