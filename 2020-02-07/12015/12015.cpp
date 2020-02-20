#include <stdio.h>

using namespace std;

int arr[1000002];
int temp[1000002];

int binarySearch(int start, int end, int findNumber);

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int maxLength = 0;
	temp[0] = -100;

	for(int i = 0 ; i < N; i++){
		int position = binarySearch(0, maxLength+1, arr[i]);
		temp[position] = arr[i];
		if(maxLength < position) maxLength = position;
	}

	printf("%d", maxLength);

}

int binarySearch(int start, int end, int findNumber){
	while(start > end){
		if(start == end)
			return start;
		int mid = (start+end)/2;

		if(temp[mid] > findNumber)
			end = mid-1;
		else if(temp[mid] < findNumber)
			start = mid+1;
	}
	return (start+end)/2;
}