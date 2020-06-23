#include <cstdio>

int N, M;
int visited[202], rank[202], road[1003];

void input();
void init();
void merge(int start, int end);
int find(int a);

int main(){
	input();

	for(int i = 1; i <= N; i++)
		printf("%d %d\n", find(visited[i]), visited[i]);

	for(int i = 1; i <= N; i++)
		printf("%d %d\n", find(visited[i]), visited[i]);
	// for(int i = 0; i < M-1; i++){
	// 	if(find(road[i]) != find(road[i+1])){
	// 		printf("NO");
	// 		return 0;
	// 	}
	// }
	// printf("YES");
}

void input(){
	int num;
	scanf("%d %d", &N, &M);
	init();
	for(int start = 1; start <= N; start++){
		for(int end = 1; end <= N; end++){
			scanf("%d", &num);
			if(num == 1 && start < end)
				merge(start, end);
		}
	}
	int point = 0;
	for(int i = 0; i < M; i++){
		scanf("%d", &road[i]);
	}
}

void init(){
	for(int i = 1; i <= N; i++)
		visited[i] = i;
}

int find(int a){
	if(visited[a] == a)
		return a;
	return visited[a] = find(visited[a]);
}

void merge(int start, int end){
	start = find(start);
	end = find(end);

	if(start == end)
		return;

	visited[start] = end;
}