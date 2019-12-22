#include <stdio.h>

int size= 4;

void perm(char data[], int n);
void swap(char data[], int start, int end);

int main(){
	char data[4] = {'a', 'b', 'c', 'd'};
	perm(data, 0);
}

void perm(char data[], int n){
	if(n == size){
		for(int i = 0; i < size; i++)
			printf(" %c ", data[i]);
		printf("\n");
		return ;
	}else{
		for(int i = n; i < size; i++){
			swap(data,i, n);
			perm(data, n+1);
			swap(data,i,n);
		}
	}
}

void swap(char data[], int start, int end){
	char temp = data[start];
	data[start] = data[end];
	data[end] = temp;
}