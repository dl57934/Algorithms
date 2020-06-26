#include <cstdio>
#include <vector>

using namespace std;

vector <int> map[102];
int check[102];
int result[102][102];
int N;
int initStart;
void input();
void init();
void dfs(int start);

int main(){
	input();

	for(int start = 1; start <= N; start++){
		initStart = start;
		dfs(start);
		init();
	}
	
	for(int start = 1; start <= N; start++){
		for(int end = 1; end <= N; end++){
			printf("%d ", result[start][end]);
		}
		printf("\n");
	}
}

void init(){
	for(int i = 1; i <= 100; i++)
		check[i] = 0;
}

void input(){
	int value;
	scanf("%d", &N);
	for(int start = 1; start <= N; start++){
		for(int end = 1; end <= N; end++){
			scanf("%d", &value);
			if(value == 1){
				map[start].push_back(end);
			}
		}	
	}
}

void dfs(int start){
	check[start] = 1;

	for(auto nextPoint : map[start]){
		result[initStart][nextPoint] = 1;
		if(!check[nextPoint]){
			dfs(nextPoint);
		}
	}
}


