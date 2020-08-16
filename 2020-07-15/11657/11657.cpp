#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

vector <pair<ll, ll> > vc;
ll INF = 987654321;
int road[503][503];
ll vertex[503];
int N, M;
void input();
void init();
void ford();

int main(){
	init();
	input();
	ford();
	for(auto next : vc){
		int start = next.first;
		int end = next.second;

		if(vertex[start] == INF)
				continue;

		if(vertex[end] > road[start][end] + vertex[start]){
			printf("-1");
			return 0;
		}
	}

	for(int vert = 2; vert <= N; vert++){
		if(vertex[vert] == INF)
			printf("-1\n");
		else
			printf("%lld\n", vertex[vert]);

	}
}

void input(){
	int a, b, c;
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &a, &b ,&c);
		if(road[a][b] == 0){
			road[a][b] = c;	
			vc.push_back(make_pair(a, b));
		}else{
			road[a][b] = min(road[a][b], c);
		}
		
	}
}

void init(){
	for(int i = 1; i <= 501; i++)
		vertex[i] = INF;
}

void ford(){
	vertex[1] = 0;

	for(int vert = 1; vert <= N; vert++){
		for(auto next : vc){
			int start = next.first;
			int endPoint = next.second;
			if(vertex[start] == INF)
				continue;

			if(vertex[endPoint] > road[start][endPoint] + vertex[start]){
				vertex[endPoint] = road[start][endPoint] + vertex[start];
			}
		}
	}

}