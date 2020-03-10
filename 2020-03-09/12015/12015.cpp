#include <cstdio>

int N, arr[1000002];
int temp[1000002];	
int index = 0;
int index2 = 0;

int binary_search(int start, int end, int sideValue);

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for(int i = 0; i < N; i++){
		if(temp[index] < arr[i] ){
			temp[index+1] = arr[i];
			index++;
		}else{
			int replaceIndex = binary_search(0, index-1, arr[i]);
			temp[replaceIndex] = arr[i];
		}
	}

	printf("%d", index);

}

int binary_search(int start, int end, int sideValue){
	int midIndex = (start+end)/2;

	if(start > end)
		return start;

	if(temp[midIndex] == sideValue){
		return midIndex;
	}

	if(temp[midIndex-1] < sideValue && temp[midIndex] > sideValue){
		return midIndex;
	}else{
		if(temp[midIndex] < sideValue){
			return binary_search(midIndex+1, end, sideValue);
		}else{
			return binary_search(start, midIndex-1, sideValue);
		}
	}
}