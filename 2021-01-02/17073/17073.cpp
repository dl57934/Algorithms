#include <cstdio>
#include <vector>

#define ll long long

using namespace std;
int visited[500002];

int main(){
	ll N, W;
	scanf("%lld %lld", &N, &W);
	int u, v;
	for(int i = 0; i < N-1; i++){
		scanf("%d %d", &u, &v);
		if(visited[u] < 2)
			visited[u]++;
		if(visited[v] < 2)
			visited[v]++;
	}

	int count = 0;
	for(int i = 2; i <= N; i++){
		if(visited[i] == 1)
			count++;
	}

	printf("%.6lf", (double)W/count);
}