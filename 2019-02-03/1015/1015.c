#include <stdio.h>


typedef struct _element{
	int seat;
	int value;
}elements;

elements element[52];
elements copyelement[52];
elements result[52];
void mergesort(int start, int end);
void merge(int start, int mid, int end);

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &element[i].value);
		element[i].seat = i;
		copyelement[i] = element[i];
	}

	mergesort(0, N-1);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(element[i].seat == copyelement[j].seat){
				result[j].seat = i;
				break;
			}
		}
	}
	for(int i = 0; i < N; i++){
		printf("%d ", result[i].seat);
	}
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
	elements temp[53];
	int part1 = start, part2 =mid+1;
	int index = start;

	for(int i = start; i<=end; i++)
		temp[i] = element[i];

	while(part1<=mid && part2<=end){
		int part1value = temp[part1].value;
		int part2value = temp[part2].value;
		if(part1value < part2value){
			element[index] = temp[part1];
			part1+=1;
		}else if(part1value == part2value){
			if(temp[part1].seat < temp[part2].seat){
				element[index] = temp[part1];
				part1+=1;
			}else{
				element[index] = temp[part2];
				part2+=1;
			}
		}
		else{
			element[index] = temp[part2];
			part2+=1;
		}	
		index+=1;	
	}

	for(int i = 0; i <= mid-part1; i++)
		element[i+index] = temp[part1+i];
}