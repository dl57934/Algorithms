#include <stdio.h>
#include <algorithm>

using namespace std;

int N, C;

long long arr[200002];
void input();

int main(){
	input();
	int maxDiff = arr[N-1]-arr[0], minDiff = 1;
	int result;

	while(minDiff <= maxDiff){
		int index = 0;
		int count = 1;
		int mid = (maxDiff+minDiff)/2;
		for(int i = 1; i < N; i++){
			if(arr[i] >= arr[index] + mid){
				index = i;
				count++;
			}
		}
		if(count < C){
			
			maxDiff=mid-1;			
		}
		else if(count >= C){
			result = mid;
			minDiff=mid+1;
		}
	}

	printf("%d", result);
}

void input(){
	scanf("%d %d", &N, &C);

	for(int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);

	sort(arr, arr+N);
}