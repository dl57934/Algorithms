#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int N, M;
const ll INF = 987654321;
ll map[1002][1002], vertex[1002];
vector<pair<ll, ll> > road;

void input(){
	ll A, B, C;
	scanf("%d %d", &N, &M);

	for(int i = 1; i <= N; i++)
		vertex[i] = INF;

	for(int i = 0; i < M; i++){
		scanf("%lld %lld %lld", &A, &B, &C);
		if(map[A][B] == 0){
			road.push_back(make_pair(A, B));
			map[A][B] = C;
		}else{
			map[A][B] = min(C, map[A][B]);
		}
	}
}

void ford(){
	vertex[1] = 0;
	for(int i = 1; i <= N; i++){
		for(auto ver : road){
			int start = ver.first;
			int destination = ver.second;
			if(vertex[start] == INF)
				continue;
			if(vertex[destination] > vertex[start] + map[start][destination]){
				vertex[destination] = vertex[start] + map[start][destination];
			}
		}
	}
}

int main(){
	input();
	ford();
	for(auto ver : road){
		int start = ver.first;
		int destination = ver.second;

		if(vertex[start] == INF)
				continue;
		if(vertex[destination] > vertex[start] + map[start][destination]){
			printf("-1");
			return 0;
		}
	}

	for(int i = 2; i <= N; i++){
		if(vertex[i] == INF)
			printf("-1\n");
		else
			printf("%lld\n", vertex[i]);
	}
}