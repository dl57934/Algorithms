#include <cstdio>

using namespace std;

int N, M;
int start, end;
int babel[102][102];
int check[102][102];

int main(){
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++){
		scanf("%d %d", &start, &end);
		babel[start][end] = 1;
	}

	for(int mid = 1; mid <= N; mid++){
		for(int start = 1; start <= N; start++){
			for(int destination = 1; destination <= N; destination++){
				if((babel[start][mid] && babel[mid][destination]) || babel[start][destination]) {
					babel[start][destination] = 1;
					check[start][destination] = 1;
				}
			}
		}
	}

	for(int base = 1; base <= N; base++){
		int count = 0;
		for(int compare = 1; compare <= N; compare++){
			if(base != compare && (check[base][compare] || check[compare][base])){
				count++;
			}
		}
		printf("%d\n", N - (count + 1));
	}
}