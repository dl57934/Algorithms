#include <cstdio>

long long arr[103][11];
int main(){
	int N;
	scanf("%d", &N);

	for(int i = 1; i < 10; i++)
		arr[0][i] = 1; 

	for(int i = 1; i <= N; i++){
		arr[i][0] = arr[i-1][1];
		for(int j = 1; j < 10; j++){
			arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1])%1000000000;
		}
	}

	long long result = 0;
	for(int i = 0; i <= 9; i++)
		result += arr[N-1][i] %1000000000;

	printf("%lld", result%1000000000);
}