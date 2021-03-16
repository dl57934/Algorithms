#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
vector<pair<ll, pair<ll, ll> > > vc;

typedef struct Disjoint{
	int parent[10002];

	void set(int v){
		for(int i = 1; i <= v; i++)
			parent[i] = i;
	}

	int find(int a){
		if(parent[a] == a)
			return a;
		return parent[a] = find(parent[a]);
	}

	void merge(int a, int b){
		a = find(a), b = find(b);

		if(a == b)
			return ;

		parent[a] = b;
	}
}Disjoint;


int main(){
	int V, E;
	ll A, B, C, result = 0;
	scanf("%d %d", &V, &E);
	Disjoint disjoint;

	disjoint.set(V);

	for(int edge = 0; edge < E; edge++){
		scanf("%lld %lld %lld", &A, &B, &C);
		vc.push_back(make_pair(C, make_pair(A, B)));
	}

	sort(vc.begin(), vc.end());

	for(auto edge : vc){
		int cost = edge.first;
		int u = edge.second.first, v = edge.second.second;

		if(disjoint.find(u) == disjoint.find(v)) continue;

		disjoint.merge(u, v);
		result+=cost;
	}

	printf("%lld", result);
}





#include <stdio.h>
#include <unistd.h>

int main(){
	int pid, gid;
	printf("[PARENT] PID = %d GID = %d\n", getpid(), getpgrp());
	pid = fork();
	if(pid == 0){
		setpgid(0, 0);
		printf("[CHILD] PID = %d GID = %d\n", getpid(), getpgrp());
	}
}

