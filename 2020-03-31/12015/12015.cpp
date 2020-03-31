#include <cstdio>

int index = 0;
int N;
int arr[1000002];
int tem[1000002];

void input();
int binarySearch(int start, int end, int findNumbers);

int main(){
	input();

	for(int i = 0; i < N; i++){
		if( i == 0){
			tem[index] = arr[i];
			index++;
		}
		else if(tem[index-1] < arr[i]){
			tem[index] = arr[i];
			index++;
		}else{
			tem[binarySearch(0, index-1, arr[i])] = arr[i];
		}	
	}

	printf("%d", index);
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
}

int binarySearch(int start, int end, int findNumbers){
	if(start > end)
		return start;
	int midIndex = (start + end)/2;

	if(tem[midIndex] == findNumbers){
		return midIndex;
	}else if(tem[midIndex] > findNumbers){
		return binarySearch( start, midIndex-1,findNumbers);
	}else{
		return binarySearch( midIndex+1, end,findNumbers);
	}
}