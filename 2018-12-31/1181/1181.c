#include <stdio.h>
#include <string.h>

void mergeSort(char arr[], char temp[], int start, int end);
void merge(char arr[], char temp[], int start, int mid, int end);

int main(N){
	char arr[20001][52];
	char temp[20001][52];
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%s", &arr[i]);

	}
	mergeSort(arr, temp, 0, N-1);

	for(int i = 0; i < N; i++)
		printf("%s\n", arr[i]);

}

void mergeSort(char arr[], char temp[], int start, int end){
	if(start < end){
		int mid =  (start+end)/2;
		mergeSort(arr, temp, start, mid);
		mergeSort(arr, temp, mid+1, end);
		merge(arr, temp, start, mid, end);
	}
}

void merge(char arr[], char temp[], int start, int mid, int end){
	for(int i = start; i <=end; i++)
		strcpy(&temp[i], &arr[i]);

	int part1 = start;
	int part2 = mid+1;
	int index = start;

	while(part1 <= mid && part2 <= end){
		if(strcmp(&temp[part1], &temp[part2]) > 0){
			strcpy(&arr[index], &temp[part1]);
			part1++;
		}else{
			strcpy(&arr[index], &temp[part2]);
			part2++;
		}
		index++;
	}

	for(int i = 0; i <= mid-part1; i++)
		strcpy(&arr[index+i], &temp[part1+i]);
}