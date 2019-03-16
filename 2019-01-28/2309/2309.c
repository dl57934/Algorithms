#include <stdio.h>

void mergesort(int start, int end);
void merge(int start,int mid, int end);
int arr[10];
int selectarr[7] = {0,};

int main(){
	int sum = 0, cnt=0;
	for(int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);

	mergesort(0, 8);

	for(int i = 0; i < 9; i++){
		for(int j = i+1; j < 9; j++){
			for(int k=0; k < 9; k++){
				if(k!=j && k!=i){
					sum+=arr[k];
					selectarr[cnt]=k;
					cnt++;
				}
			}
			
			if(sum == 100){
				for(int i = 0; i < 7; i++)
					printf("%d\n", arr[selectarr[i]]);
				return 0;
			}
			else{
				cnt=0;
				sum=0;
			}
		}
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

void merge(start, mid, end){
	int temp[11];
	int part1 = start;
	int part2 = mid+1;
	int index = start;
	for(int i=start; i <= end; i++)
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
	for(int i=0; i <= mid-part1; i++)
		arr[i+index] = temp[part1+i];

}


