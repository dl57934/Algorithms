#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

void mergeSort(string arr[],int start, int end);
void merge(string arr[], int start, int mid, int end);
int getSize(string temp[], int index);
void inputModifiedElement(string arr[],string temp[],int index,int *part1);

int main(){
	int N;
	int isSame = 1;
	string letters[20002];
	scanf("%d", &N);

	for(int i =0; i < N; i++)
		 cin>>  letters[i];
	mergeSort(letters, 0, N-1);	
	for(int i =0; i < N; i++){
		if(letters[i].compare(letters[i+1]) == 0)
			isSame = 0;
		else 
			isSame = 1;
		if(isSame)
		 printf("%s\n", letters[i].c_str());
	}
}

void mergeSort(string arr[], int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

void merge(string arr[], int start, int mid, int end){
	string temp[20002];
	int part1 = start;
	int part2 = mid+1;
	int index = start;

	for(int i = start; i <= end; i++)
		temp[i] = arr[i];

	while( part1<=mid && part2<=end ){
		if(getSize(temp, part1) == getSize(temp, part2)){
			if(temp[part1].compare(temp[part2]) < 0){
				inputModifiedElement(arr, temp, index, &part1);
			}else{
				inputModifiedElement(arr, temp, index, &part2);
			}
		}
		else if(getSize(temp, part1) < getSize(temp, part2)){
			inputModifiedElement(arr, temp, index, &part1);
		}
		else{
			inputModifiedElement(arr, temp, index, &part2);
		}
		index ++;
	}

	for(int i = 0; i <=mid-part1 ;i++){
		arr[index+i] = temp[part1+i];
	}
}

int getSize(string temp[], int index){
	return temp[index].size();
}

void inputModifiedElement(string arr[], string temp[], int index, int *part1){
	arr[index] = temp[*part1];
	*part1+=1;
}



