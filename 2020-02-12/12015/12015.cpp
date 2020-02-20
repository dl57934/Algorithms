#include <cstdio>

int N;
int arr[1000002];
int temp[1000002];
int binarySearch(int start, int end, int findNum);
int allCount = 0;
int compareNumber = 0;
int saver = 0;

int main(){
	scanf("%d", &N);	

	for(int i = 0 ; i < N; i++)
		scanf("%d", &arr[i]);
	
	for(int i = 0; i < N; i++){
		int findIndex = binarySearch(0, allCount, arr[i]);	
		// 나왔던 수
		// 처음 나왔지만 큰 수
		// 처음 나왔지만 작은 수  
		if(temp[findIndex] != arr[i]){
			if(arr[i] < temp[allCount-1]){
				temp[findIndex] = arr[i];
			}
			else if(arr[i] > temp[allCount-1]){
				temp[allCount] = arr[i];
				allCount+=1;
			}
		}
		
	}
	printf("%d", allCount);
}


int binarySearch(int start, int end, int findNum){
	while(start <= end){
		int mid = (start+end)/2;

		if(temp[mid] == findNum)
			return mid;
		else if(temp[mid] > findNum)
			end=mid-1;
		else
			start=mid+1;
	}

	return start;
}