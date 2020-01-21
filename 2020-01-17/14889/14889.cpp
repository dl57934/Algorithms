#include <stdio.h>
#include <stdlib.h>

int N;
int stat[22][22];
int stark=0, link=0;
int different = 1000000;
int member = 0;
int arr[21];

void selectMembers(int limit);
void swap(int i, int j);
void mergeStat(int teamName);
int isUpside();

int main(){
	scanf("%d", &N);
	member = N/2;

	for(int i = 0; i < N; i++)
		arr[i] = i;

	for(int width = 0 ; width < N; width++)
		for(int height = 0 ; height < N; height++)
			scanf("%d", &stat[height][width]);
			
	selectMembers(0);

	printf("%d", different);

}

void selectMembers(int limit){
	if(limit == member){

	}

	for(int i = limit; i < N; i++){
		selectMembers()
	}
}

int isUpside(){
	for(int i = 1; i < member; i++)
		if(arr[i] < arr[i-1])
			return 0;
	return 1;

}

void swap(int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}