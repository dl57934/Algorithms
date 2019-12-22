#include <stdio.h>

int arr[12] = {3, 5, 2, 3, 4,1,5 ,6};

void insertion(int n);
void swap(int i, int j);
int main(){
	insertion(0);
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
}

void insertion(int n){
	for(int i =0; i < 7; i++){
		int least = i;
		for(int j = i+1; j <8; j++)
			if(arr[least] > arr[j])
				least = j;

		if(i != least)
			swap(i, least);

	}

}

void swap(int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}