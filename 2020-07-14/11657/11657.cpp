#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define point pair<ll, ll>
int N, M;
vector <point> vc;
ll map[502][502];
ll vertex[502];
ll INF = 9876543;
void input();
void ford();

int main(){
	input();
	ford();

	for(auto now : vc){
		int start = now.first;
		int endPoint = now.second;

		if(vertex[start] == INF)
			continue;
		if(vertex[start] + map[start][endPoint] < vertex[endPoint]){
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
		if(map[A][B] == 0){
			map[A][B] = C;
			vc.push_back(make_pair(A, B));
		}else{
			map[A][B] = min(map[A][B], C);
		}
	}

	for(int i = 1 ; i <= N; i++)
		vertex[i] = INF;

	vertex[1] = 0;
}

void ford(){
	for(int i = 1; i <= N; i++){
		for(auto now : vc){
			int start = now.first;
			int endPoint = now.second;

			if(vertex[start] == INF)
				continue;

			if(vertex[start] + map[start][endPoint] < vertex[endPoint]){
				vertex[endPoint] = vertex[start] + map[start][endPoint];
			}
		}
	}
}