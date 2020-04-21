#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int N;
int arr[1000002];
int dp[1000002];
int result[1000002];
int testIndex;
stack <int> st;

void input();
void getMaxLenght();

int main(){
	input();
	getMaxLenght();
	printf("%d\n", testIndex+1);
	int findLength = 0;
	for(int i = N-1; i>=0; i--){
		if(testIndex == result[i]){
			st.push(arr[i]);
			testIndex--;
		}
	}

	while(!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
}

void getMaxLenght(){
	dp[0] = arr[0];
	for(int i = 0; i < N; i++){
		if(dp[testIndex] < arr[i]){
			testIndex++;
			dp[testIndex] = arr[i];
			result[i] = testIndex;
		}else{
			int lowerIndex = lower_bound(dp, dp+testIndex, arr[i]) - dp;
			dp[lowerIndex] = arr[i];
			result[i] = lowerIndex;
		}
	}
}