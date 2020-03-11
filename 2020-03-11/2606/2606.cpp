#include <cstdio>

int map[102][102];

int visit[102];

int virusComputer = 0;
int computer = 0;
int computerLine = 0;
int start = 0, end = 0;

void setMap(int start, int end, int value);
void dfs(int start, int end);

int main(){
	scanf("%d", &computer);
	scanf("%d", &computerLine);

	for(int i = 0; i < computerLine; i++){
		scanf("%d %d", &start, &end);
		setMap(start, end, 1);
	}

	for(int i = 2; i <= computer; i++) {
		if(map[1][i] == 1){
			dfs(1, i);
		}
	}
	
	printf("%d", virusComputer);
}

void dfs(int start, int end){
	setMap(start, end, 0);
	if(!visit[end] && end != 1){
		visit[end] = 1;
		virusComputer+=1;
	}

	for(int i = 1; i <= computer; i++){
		if(map[end][i]){
			dfs(end, i);
		}
	}
}

void setMap(int start, int end, int value){
	map[start][end] = value;
	map[end][start] = value;
}