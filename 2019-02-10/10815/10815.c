#include <stdio.h>

typedef struct _findCard{
	int value;
	int position;
}findCard;

void quicksort(int start, findCard arr[], int end);
int partition(int start, findCard arr[],int end);
void swap(int a, findCard arr[], int b);
void input(int *N, int *M);
int binarySearch(findCard arr[], int target, int start, int end);

int sangCard[500002]={0 ,};
findCard card[500002]={0 ,};
int cpCard[500002]={0 ,};

int main(){
	int N, M;
	input(&N, &M);
	quicksort(0, card, M-1);
	for(int i = 0; i < N; i++){
		int result = binarySearch(card, sangCard[i], 0, M-1);
		if(result != -1)
			cpCard[card[result].position]=1;
	}

	for(int i = 0; i < M; i++)
		printf("%d ", cpCard[i]);
}

int binarySearch(findCard arr[], int target, int start, int end){
	int mid;
	while(start <= end){
		mid = (start+end)/2;
		if(arr[mid].value == target)
			return mid;
		else if(arr[mid].value < target)
			start=mid+1;
		else if(arr[mid].value > target)	
			end=mid-1;
	}	
	return -1;
}

void input(int *N, int *M){
	scanf("%d", N);
	for(int i = 0; i < *N; i++)
		scanf("%d", &sangCard[i]);
	scanf("%d", M);
	for(int i = 0; i < *M; i++){
		scanf("%d", &card[i].value);
		card[i].position = i;
	}
}


void quicksort(int start, findCard arr[], int end){
	if(start < end){
		int part = partition(start, arr, end);
		quicksort(start, arr, part-1);
		quicksort(part, arr, end);
	}
}
int partition(int start, findCard arr[],int end){
	int pivot = arr[(start+end)/2].value;
	while(start<=end){
		while(arr[start].value<pivot)start++;
		while(arr[end].value>pivot)end--;
		if(start <= end){
			swap(start, arr, end);
			start++;
			end--;
		}
	}
	return start;
}
void swap(int a, findCard arr[], int b){
	findCard temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}