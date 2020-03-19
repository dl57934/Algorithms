#include <cstdio>

int N, T;

int value[502];
int sum[502];
int arr[502][502];

void input();
void getMininumFileSize();

int main(){
	input();
}

void input(){
	scanf("%d", &T);

	for(int testCase = 0; testCase < T; testCase++){
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%d", &value[i]);
			sum[i] = sum[i-1] + value[i];
		}
		getMininumFileSize();

		printf("%d\n", arr[0][N-1]);
	}
}

void getMininumFileSize(){
	for(int i = 0; i < N; i++)
		arr[i][i] = 0;

	for(int difference = 1; difference < N; difference++){
		for(int i = 0; i < N-difference; i++){
			int j = i + difference;
			int min = 987654321;
			for(int k = i; k < j; k++){
				int point = arr[i][k] + arr[k+1][j] + sum[j] - sum[i-1];
				if(min > point)
					min = point;
			}
			arr[i][j] = min;
		}
	}
}