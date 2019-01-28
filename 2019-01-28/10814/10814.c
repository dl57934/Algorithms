#include <stdio.h>
#include <stdlib.h>

typedef struct _group{
	int order;
	int age;
	char name[103];
}group;

group members[100002];

void sort(int start, int end);
void merge(int start, int mid, int end);
void upPart(group temp[], int index, int *part);

int main(){
	int N;
	scanf("%d", &N);
	for(int i =0; i < N; i++){
		scanf("%d %s", &members[i].age, members[i].name);
		members[i].order = i;
	}
	sort(0, N-1);
	for(int i = 0; i < N; i++)
		printf("%d %s\n", members[i].age, members[i].name);
}

void sort(int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		sort(start, mid);
		sort(mid+1, end);
		merge(start, mid, end);
	}
}
void merge(int start, int mid, int end){
	group temp[end+2];
	int part1 = start;
	int part2 = mid+1;
	int index = start;

	for(int i = start; i <= end; i++)
		temp[i] = members[i];

	while(part1<=mid && part2 <=end){
		if(temp[part1].age < temp[part2].age)
			upPart(temp, index, &part1);
		else if(temp[part1].age > temp[part2].age)
			upPart(temp, index, &part2);
		else{
			if(temp[part1].order < temp[part2].order)
				upPart(temp, index, &part1);
			else
				upPart(temp, index, &part2);	
		}
		index++;
	}

	for(int i = 0; i <= mid-part1; i++)
		members[i+index] = temp[part1+i];
}


void upPart(group temp[], int index, int *part){
	members[index] = temp[*part];
	(*part)++;
}