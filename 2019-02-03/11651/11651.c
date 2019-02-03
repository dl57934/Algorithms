#include <stdio.h>

typedef struct _point{
	int x;
	int y;
}point;

point xy[100002];

void mergesort(int start, int end);
void merge(int start, int mid, int end);


int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &xy[i].x, &xy[i].y);
	mergesort(0, N-1);
	for(int i = 0; i < N; i++)
		printf("%d %d\n", xy[i].x, xy[i].y);
}

void mergesort(int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		mergesort(start, mid);
		mergesort(mid+1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end){
	int part1 = start, part2 = mid+1;
	int index = start; 
	point temp[100002];
	for(int i = start; i <= end; i++){
		temp[i] = xy[i];
	}

	while(part1 <= mid && part2 <= end){
		if(temp[part1].y < temp[part2].y){
			xy[index] = temp[part1];
			part1++;
		}else if(temp[part1].y == temp[part2].y){
			if(temp[part1].x < temp[part2].x){
				xy[index] = temp[part1];
				part1++;
			}else{
				xy[index] = temp[part2];
				part2++;
			}
		}else {
			xy[index] = temp[part2];
			part2++;
		}
		index+=1;
	}

	for(int i =0; i <= mid-part1; i++)
		xy[i+index] = temp[part1+i];
}
