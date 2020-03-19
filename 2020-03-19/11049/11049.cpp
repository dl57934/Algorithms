#include <cstdio>
#include <algorithm>

using namespace std;

int arr[502][502];
int size[502][3];

int N;

void getMultyplyOrder();

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d %d", &size[i][0], &size[i][1]);

	for(int i = 0; i < N; i++)
		arr[i][i] = 0;

	getMultyplyOrder();

	printf("%d", arr[0][N-1]);
}

void getMultyplyOrder(){
	for (int difference = 1; difference < N; difference++){
		for(int i = 0; i < N-difference; i++){
			int j = i + difference;
			int min = 987654321;
			for(int k = i; k < j; k++){
				int point = arr[i][k] + arr[k+1][j] + size[i][0] * size[k][1] * size[j][1];
				if(min > point)
					min = point;
			}
			arr[i][j] = min;
		}
	}
}