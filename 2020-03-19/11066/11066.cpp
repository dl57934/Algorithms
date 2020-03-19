#include <cstdio>

int T;
int N;
int value[502];
int sum[502];
int arr[502][502];


void init();
void input();
void calculator();

int main(){
	init();
	input();
	
}

void input(){
	scanf("%d", &T);
	for(int attempt = 0; attempt < T; attempt++){
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%d", &value[i]);
			 sum[i] = value[i] + sum[i-1];
		}
		
		calculator();
	}
	

}

void calculator(){
	int count = N;
	int index = 0;

	for(int difference = 1; difference < N; difference++){
		for(int i = 0; i < N-difference; i++){
			int min = 987654321;
			int j = i + difference;
			for(int k = i; k < j; k++){
				int point = arr[i][k] + arr[k+1][j] - sum[i-1] + sum[j];
				if(point < min)
					min = point;
			}
			arr[i][j] = min;
		}
	}

	
	printf("%d\n",arr[0][N-1]);
}

void init(){
	for(int i = 0; i < 500; i++)
		arr[i][i] = 0;
}