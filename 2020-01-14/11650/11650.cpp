#include <stdio.h>

void mergeSort(int start, int end);
void merge(int start, int mid, int end);

typedef struct pointer{
	int x;
	int y;
}pointer;

pointer point[100004];

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N;i++)
		scanf("%d %d", &point[i].x, &point[i].y);
	
	mergeSort(0, N-1);

	for(int i = 0; i < N;i++)
		printf("%d %d\n", point[i].x, point[i].y);
}

void mergeSort(int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		mergeSort(start, mid);
		mergeSort(mid+1, end);
		merge(start, mid, end);
	}
}
void merge(int start, int mid, int end){
	pointer temp[100004];
	int part1 = start, part2 = mid+1;
	int index = start;
	for(int i = start; i<=end; i++)
		temp[i] = point[i];

	while(part1 <= mid && part2 <= end){
		if(temp[part1].x < temp[part2].x){
			point[index] = temp[part1];
			part1++;
		}
		else if(temp[part1].x == temp[part2].x){
			if(temp[part1].y < temp[part2].y){
				point[index] = temp[part1];
				part1++;
			}else{
				point[index] = temp[part2];
				part2++;
			}
		}
		else{
			point[index] = temp[part2];
			part2++;
		}
		index+=1;
	}

	for(int i = 0; i <= mid-part1; i++)
		point[index+i] = temp[part1+i];
}