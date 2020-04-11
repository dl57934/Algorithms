#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 987654321;
int N, M;
int map[502][502];
int vertex[502];
vector <pair<int, int> > vec;

void ford();
void input();

int main(){
	input();
	ford();

	for(int line = 0; line < vec.size(); line++){
			pair<int, int> info = vec[line];
			int start = info.first;
			int end = info.second;
			if(vertex[start] == INF)
				continue;
			if(vertex[end] > map[start][end] + vertex[start]){
				printf("-1");
				return 0;
			}
	}


	for(int i = 2; i <= N; i++){
		if(vertex[i] == INF)
			printf("-1\n");
		else
			printf("%d\n", vertex[i]);
	}
}

void input(){
	int a, b, c;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(map[a][b] == 0){
			map[a][b] = c;
			vec.push_back(make_pair(a, b));
		}
		else
			map[a][b] = min(map[a][b], c);
	}

	for(int i = 1; i <= N; i++)
		vertex[i] = INF;
	vertex[1] = 0;
}

void ford(){
	for(int ver = 1; ver <= N; ver++){
		for(int line = 0; line < vec.size(); line++){
			pair<int, int> info = vec[line];
			int start = info.first;
			int end = info.second;
			if(vertex[start] == INF)
				continue;
			if(vertex[end] > map[start][end] + vertex[start]){
				vertex[end] = map[start][end] + vertex[start];
			}
		}
	}
}