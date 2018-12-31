#include <stdio.h>
#include <string.h>

int arr[500001];
int mode[8002]={0, };
int modeMaxArr[8002]={0, };

int getMedian(int N);
float getAverage(int N, float sum);
int getMode(int N);
int getDifference(int N);
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void swap(int arr[], int start, int end);

int main(N){
	float sum;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
		mode[arr[i]+4000]+=1;
	}
	quickSort(arr, 0, N-1);


	printf("%.0f\n", getAverage(N, sum));
	printf("%d\n", getMedian(N));
	printf("%d\n", getMode(N));
	printf("%d\n", getDifference(N));
}

float getAverage(int N, float sum){
	return sum/N;
}

int getMode(int N){
	int max = 0;
	int count = 0;
	for(int i = 0; i < 8001; i++)
		if(max < mode[i])
			max = mode[i];
	for(int i = 0; i < 8001; i++){
		if(max == mode[i]){
			modeMaxArr[count] = i;
			count++;
		}
	}
	if(count > 1)
		return modeMaxArr[1]-4000;
	else 
		return modeMaxArr[0]-4000; 	
}

int getMedian(int N){
	return arr[N/2];
}

int getDifference(int N){
	return arr[N-1] - arr[0];
}

void quickSort(int arr[], int start, int end){
	int part2 = partition(arr, start, end);
	if(start < part2-1)
		quickSort(arr, start, part2-1);
	if(part2 < end)
		quickSort(arr, part2, end);
}

int partition(int arr[], int start, int end){
	int pivot = arr[(start+end)/2];
	while(start <= end){
		while(arr[start] < pivot)start++;
		while(arr[end] > pivot) end--;

		if(start <= end){
			swap(arr, start, end);
			start++;
			end--;
		}
	}
	return start;
}

void swap(int arr[], int start, int end){
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
} 