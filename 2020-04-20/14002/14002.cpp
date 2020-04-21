#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int arr[10002];
int dp[10002];
int discover[100002];

void input();
void getMaxLength();

int main(){
	input();
	getMaxLength();
	int result = *max_element(dp, dp + N);
	int size = result;
	printf("%d\n", result);

	for(int i = N-1; i >= 0; i--){
		if(dp[i] == result){
			discover[result] = arr[i];
			result--;
		}
	}

	for(int i = 1; i <= size; i++)
		printf("%d ", discover[i]);
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
}

void getMaxLength(){
	for(int i = 0; i < N; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
 			}
		}
	}
}