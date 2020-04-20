#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int color[1002][3];
int zero[1002][3];
int one[1002][3];
int two[1002][3];
int result[4];

void input();

int main(){
	input();

	zero[1][0] = color[1][0]; //10 
	zero[2][1] = zero[1][0] + color[2][1]; // 30
	zero[2][2] = zero[1][0] + color[2][2]; //40
	zero[2][0] = 999999;

 	for(int i = 3; i <= N-1; i++){
		zero[i][0] = min(zero[i-1][1], zero[i-1][2]) + color[i][0];
		zero[i][1] = min(zero[i-1][0], zero[i-1][2]) + color[i][1];
		zero[i][2] = min(zero[i-1][1], zero[i-1][0]) + color[i][2];
	}

	zero[N][1] = color[N][1] + min(zero[N-1][2], zero[N-1][0]);
	zero[N][2] = color[N][2] + min(zero[N-1][1], zero[N-1][0]);
	result[0] = min(zero[N][1], zero[N][2]);
	// printf("\n%d %d %d\n", color[N][0], color[N][1], color[N][2]);
	// printf("%d %d %d\n", zero[N-1][0], zero[N-1][1], zero[N-1][2]);
	// printf("%d %d %d", result[0], result[1], result[2]);
	one[1][1] = color[1][1];
	one[2][2] = one[1][1] + color[2][2];
	one[2][0] = one[1][1] + color[2][0];
	one[2][1] = 999999;
 	for(int i = 3; i <= N-1; i++){
		one[i][0] = min(one[i-1][1], one[i-1][2]) + color[i][0];
		one[i][1] = min(one[i-1][0], one[i-1][2]) + color[i][1];
		one[i][2] = min(one[i-1][1], one[i-1][0]) + color[i][2];
	}

	one[N][0] = color[N][0] + min(one[N-1][2], one[N-1][1]);
	one[N][2] = color[N][2] + min(one[N-1][0], one[N-1][1]);
	result[1] = min(one[N][0], one[N][2]);

	two[1][2] = color[1][2];
	two[2][0] = two[1][2] + color[2][0];
	two[2][1] = two[1][2] + color[2][1];
	two[2][2] = 999999;
 	for(int i = 3; i <= N-1; i++){
		two[i][0] = min(two[i-1][1], two[i-1][2]) + color[i][0];
		two[i][1] = min(two[i-1][0], two[i-1][2]) + color[i][1];
		two[i][2] = min(two[i-1][1], two[i-1][0]) + color[i][2];
	}

	two[N][0] = color[N][0] + min(two[N-1][1], two[N-1][2]);
	two[N][1] = color[N][1] + min(two[N-1][0], two[N-1][2]);
	result[2] = min(two[N][0], two[N][1]);
	
	printf("%d", *min_element(result, result + 3));
}

void input(){
 scanf("%d", &N);
 for(int i = 1; i <= N; i++){
 	scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);
	}
}