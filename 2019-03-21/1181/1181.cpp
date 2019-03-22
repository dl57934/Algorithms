#include <string.h>
#include <cstdio>
#include <string>
#include <queue>
#define SAME 0

using namespace std;

queue <string> qu;

void mergesort(int start, int end);
void merge(int start, int mid, int end);

char words[20003][52];

int main(){
	int N;
	int isDuplicate = 0;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%s", words[i]);

	mergesort(0, N-1);

	for(int i = 0; i < N; i++){
		if(strcmp(words[i], words[i+1]) ==0)
			isDuplicate = 0;
		else 
			isDuplicate = 1;
		if(isDuplicate)
			printf("%s\n", words[i]);
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
	char temp[20003][52];

	for(int i = start; i <= end; i++)
		strcpy(temp[i], words[i]);


	int index = start, part1 = start;
	int part2 = mid+1; 

	while(part1 <= mid && part2 <= end){
		if(strlen(temp[part1]) == strlen(temp[part2])){
			if(strcmp(temp[part1], temp[part2]) < 0){
				strcpy(words[index], temp[part1]);
				part1++;
			}else{
				strcpy(words[index], temp[part2]);				
				part2++;
			}
		}else if(strlen(temp[part1]) < strlen(temp[part2])){
			strcpy(words[index], temp[part1]);
			part1++;
		} else{
			strcpy(words[index], temp[part2]);
			part2++;
		}
		index++;
	}

	for(int i = 0; i <= mid-part1; i++)
		strcpy(words[i+index], temp[i+part1]);
	
}