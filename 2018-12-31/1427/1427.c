#include <stdio.h>
#include <string.h>

void quickSort(char arr[], int start, int end);
int partition(char arr[], int start, int end);
void swap(char arr[], int start, int end);

int main(){
	char string[12];
	scanf("%s", string);
	int end = strlen(string);

	quickSort(string, 0, end-1);

	for(int i = 0; i < end; i++)
		printf("%c", string[i]);
}

void quickSort(char arr[], int start, int end){
	int part2 = partition(arr, start, end);
	if(start < part2-1)
		quickSort(arr, start, part2-1);
	if(part2 < end)
		quickSort(arr, part2, end);
}

int partition(char arr[], int start, int end){
	char pivot = arr[(start+end)/2];

	while(start<=end){
		while(arr[start] > pivot) start++;
		while(arr[end] < pivot) end--;
		if(start<=end){
			swap(arr, start, end);
			start++;
			end--;
		}
	}

	return start;
}

void swap(char arr[], int start, int end){
	char temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
}