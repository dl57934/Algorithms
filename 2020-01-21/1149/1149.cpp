#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int houseValue[1001][4];
int setValue[1001][4] = {0,};

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < 3; j++)
			scanf("%d", &houseValue[i][j]);

	setValue[0][0] = houseValue[0][0];
	setValue[0][1] = houseValue[0][1];
	setValue[0][2] = houseValue[0][2];

	for(int i = 1; i < N; i++){
		setValue[i][0] = min(setValue[i-1][1], setValue[i-1][2]) + houseValue[i][0];
		setValue[i][1] = min(setValue[i-1][0], setValue[i-1][2]) + houseValue[i][1]; 
		setValue[i][2] = min(setValue[i-1][0], setValue[i-1][1]) + houseValue[i][2];
	}

	
	printf("%d\n", min(min(setValue[N-1][0], setValue[N-1][1]), setValue[N-1][2]));
}
