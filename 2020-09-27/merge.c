#include <stdio.h>

int input1[10], input2[10];

void mergeSort(int start, int end);
void merge(int start, int mid, int end); 
void quickSort(int start, int end);
int partition(int start, int end);
void swap(int start, int end);

int main(){
	printf("Merge Sort(nlogn)\nbefore\n");
	printf("정렬하고 싶은 숫자를 입력하세요!\n");
	for(int i = 0; i < 9; i++)
		scanf("%d", &input1[i]);
	
	printf("\n");

	mergeSort(0, 8);

	printf("after\n");
	for(int i = 0; i < 9; i++)
		printf("%d ", input1[i]);

	printf("\n\nQuick Sort(nlogn ~ n^2)\nbefore\n");
	printf("정렬하고 싶은 숫자를 입력하세요!\n");
	
	for(int i = 0; i < 9; i++)
		scanf("%d", &input2[i]);
	printf("\n");

	quickSort(0, 8);

	printf("after\n");
	for(int i = 0; i < 9; i++)
		printf("%d ", input2[i]);
}

void mergeSort(int start, int end){
	if(start < end){
		int mid = (start + end)/2;
		mergeSort(start, mid);
		mergeSort(mid+1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end){
	int temp[10];
	int part1 = start, part2 = mid+1;
	int index = start;

	for(int i = start; i <= end; i++)
		temp[i] = input1[i];

	while(part1 <= mid && part2 <= end){
		if(temp[part1] > temp[part2]){
			input1[index] = temp[part2];
			part2++;
		}else{
			input1[index] = temp[part1];
			part1++;
		}
		index+=1;
	}

	for(int i = 0; i <= mid-part1; i++){
		input1[index + i] = temp[part1 + i];
	}
}

void quickSort(int start, int end){
	int partitionIndex = partition(start, end);

	if(start < partitionIndex-1)
		quickSort(start, partitionIndex-1);

	if(partitionIndex < end)
		quickSort(partitionIndex, end);
}

int partition(int start, int end){
	int pivot = input2[(start+end)/2];

	while(start < end){
		while(pivot > input2[start]){
		 	start++;
		}
		while(pivot < input2[end]) {
			end--;
		}
		if(start <= end){
			swap(start, end);
			start++;
			end--;	
		}
	}
	return start;
}

void swap(int start, int end){
	int temp =input2[start];
	input2[start] = input2[end];
	input2[end] = temp;
}
