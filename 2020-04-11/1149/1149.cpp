#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int map[1002][4];

void input();
void getColor();

int main(){
	input();
	getColor();
	printf("%d", *min_element(map[N-1], map[N-1] + 3));
}

void input(){
	int red, green, blue;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
	}
}

void getColor(){
	for(int i = 1; i < N; i++){
		map[i][0] += min(map[i-1][1], map[i-1][2]);
		map[i][1] += min(map[i-1][0], map[i-1][2]);
		map[i][2] += min(map[i-1][1], map[i-1][0]);
	}
}