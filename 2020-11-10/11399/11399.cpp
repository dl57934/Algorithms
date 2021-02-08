#include <cstdio>
#include <algorithm>

using namespace std;

int N;

int main(){
	int arr[1002], spendTime = 0, time = 0;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	sort(arr, arr + N);
	time = arr[0];
	spendTime = time;
	for(int i = 1; i < N; i++){
		time+=arr[i];
		spendTime += time;
	}

	printf("%d", spendTime);
}