#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
#define point pair<ll, ll>

using namespace std;

ll vertex[505];
ll line[505][505];
vector <point> link;
int N, M;
ll INF = 987654321;

void input();
void ford();

int main(){
	input();
	ford();

	for(auto now : link){
		int nowPoint = now.first, nextPoint = now.second;
		if(vertex[nowPoint] == INF)
				continue;
		if(vertex[nextPoint] > vertex[nowPoint] + line[nowPoint][nextPoint]){
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

void input(){
	ll A, B, C;
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++){
		scanf("%lld %lld %lld", &A, &B, &C);
		if(line[A][B] == 0){
			line[A][B] = C;
			link.push_back(make_pair(A, B));
		}else{
			line[A][B] = min(line[A][B], C);
		}
	}

	for(int i = 2; i <= N; i++)
		vertex[i] = INF;
}

void ford(){
	for(int i = 1; i <= N; i++){
		for(auto now : link){
			int nowPoint = now.first, nextPoint = now.second;
			if(vertex[nowPoint] == INF)
				continue;
			if(vertex[nextPoint] > vertex[nowPoint] + line[nowPoint][nextPoint]){
				vertex[nextPoint] = vertex[nowPoint] + line[nowPoint][nextPoint];
			}
		}
	}
}