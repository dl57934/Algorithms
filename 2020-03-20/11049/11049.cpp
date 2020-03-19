#include <cstdio>

int arr[502][502];
int size[502][3];

int N;

void getMultiplySize();
int min(int a, int b);

int main(){
	scanf("%d", &N);

	for(int y = 0; y < N; y++)
		scanf("%d %d", &size[y][0], &size[y][1]);

	getMultiplySize();

	printf("%d",arr[0][N-1]);
}

void getMultiplySize(){
	for(int i = 0; i < N; i++)
		arr[i][i] = 0;

	for(int difference = 1; difference < N; difference++){
		for(int i = 0; i < N - difference; i++){
			int j = difference + i;
			int min = 987654321;
			for(int k = i; k < j; k++){
				if(min > arr[i][k] + arr[k+1][j] + size[i][0] * size[k][1] * size[j][1])
					min = arr[i][k] + arr[k+1][j] + size[i][0] * size[k][1] * size[j][1];
			}
			arr[i][j] = min;
		}
	}
}

int min(int a, int b){
	if( a > b)
		return b;
	return a;
}