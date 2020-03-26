#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;
int bag[102][100002], item[102][2]; // 0 weight 1 value

void input();
void knaspack();

int main(){
	input();
	knaspack();
	for(int i = 0; i <= N; i++){
		for(int weight = 0; weight <= K; weight++){
			printf("%d ", bag[i][weight]);
		}
		printf("\n");
	}

	printf("%d", bag[N][K]);
}

void input(){
	scanf("%d %d", &N, &K);

	for(int i = 1; i <= N; i++)
		scanf("%d %d", &item[i][0], &item[i][1]);
}

void knaspack(){
	for(int it = 1; it <= N; it++){
		for(int weight = 1; weight <= K; weight++){
			if(item[it][0] > weight)
				bag[it][weight] = bag[it-1][weight];
			else
				bag[it][weight] = max(bag[it-1][weight], bag[it-1][weight-item[it][0]] + item[it][1]);
		}
	}
}