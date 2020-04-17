#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector <int> map[100002];
int result[100002];
int N;
queue <int> qu;

void input();
void bfs();
void output();

int main(){
	input();
	bfs();
	output();
}

void input(){
	scanf("%d", &N);
	int firstPoint, secondPoint;
	for(int i = 1; i < N; i++){
		scanf("%d %d", &firstPoint, &secondPoint);
		map[firstPoint].push_back(secondPoint);
		map[secondPoint].push_back(firstPoint);
	}
}

void bfs(){
	qu.push(1);

	while(!qu.empty()){
		int starter = qu.front();
		qu.pop();
		for(int i = 0; i < map[starter].size(); i++){
			if(result[map[starter][i]] == 0){
				result[map[starter][i]] = starter;
				qu.push(map[starter][i]);
			}
		}
	}
}

void output(){
	for(int i = 2; i <= N; i++ )
		printf("%d\n", result[i]);
}