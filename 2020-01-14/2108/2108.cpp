#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;
vector<int> maxNumbers;

int arr[500002] = {0, };
int usefulNumber[10000] = {0, };
void mergeSort(int start, int end);
void merge(int start, int mid, int end);
long double sum = 0;
int maxs=0;

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i<N;i++){
		scanf("%d", &arr[i]);
		usefulNumber[arr[i]+4000]+=1;
		sum+=arr[i];
	}
	mergeSort(0, N-1);
	//평균
	if(round(sum/N) == -0)
		printf("0\n");
	else
		printf("%.0Lf\n", round(sum/N));

	//중앙값
	printf("%d\n",arr[(N-1)/2]);

	//최빈값
	for(int i = 0; i <= 8000; i++){
		if(usefulNumber[i] > maxs){
			maxs = usefulNumber[i];
			maxNumbers.clear();
			maxNumbers.push_back(i-4000);
		}else if(usefulNumber[i] == maxs){
			maxNumbers.push_back(i-4000);
		}
	}
	if(maxNumbers.size() > 1)
		printf("%d\n", maxNumbers[1]);
	else
		printf("%d\n", maxNumbers[0]);
	//범위
	printf("%d",  arr[N-1]-arr[0]);
	
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
	int part1 = start, part2 = mid+1;
	int index = start;

	int temp[500002];

	for(int i = start; i<=end; i++)
		temp[i] = arr[i];

	while(part1<=mid && part2<=end){
		if(temp[part1] < temp[part2]){
			arr[index] = temp[part1];
			part1++;
		}else{
			arr[index] = temp[part2];
			part2++;
		}
		index++;
	}

	for(int i = 0; i <= mid-part1;i++)
		arr[i+index] = temp[part1+i];
}