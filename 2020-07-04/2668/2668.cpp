#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> sub;
int map[103];
int check[103];
int allCheck[103];
int allSize;
int N;
int cycle;
void input();
void init();
void dfs(int now);


int main(){
	input();
	for(int i = 1; i <= N; i++){
		cycle = i;
		dfs(i);
		init();
	}
	printf("%d\n", allSize);
	for(int i = 1; i <= N; i++){
		if(allCheck[i])
			printf("%d\n", i);
	}
}


void input(){
	int value;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++){
		scanf("%d", &value);
		map[i] = value;
	}
}

void dfs(int now){
	if(check[now] && now == cycle){
		for(auto s : sub){
			if(allCheck[s] == 0){
				allSize++;
				allCheck[s] = 1;
			}
		}
	}
	if(check[map[now]] == 0){
		sub.push_back(map[now]);
		check[map[now]] = 1;
		dfs(map[now]);
	}
}



void init(){
	for(int i = 1; i <= N; i++)
		check[i] = 0;
	sub.clear();
}