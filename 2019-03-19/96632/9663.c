#include <stdio.h>
#include <stdlib.h>

int queensPoint[18];
int size;
int count = 0;

void Nqueen(int queensPoint[], int n);
int promise(int queensPoint[], int n);

int main(){
	
	scanf("%d", &size);

	Nqueen(queensPoint, 0);

	printf("%d", count);
}

void Nqueen(int queensPoint[], int n){
	if(size == n)
		count+=1;
	for(int i = 0; i < size; i++){
		queensPoint[n] = i;
		if(promise(queensPoint, n))
			Nqueen(queensPoint, n+1);
	}
}

int promise(int queensPoint[], int n){
	for(int i = 0; i < n; i++){
		if(queensPoint[i] == queensPoint[n]) return 0;	
		if(abs(queensPoint[i]-queensPoint[n]) == abs(i-n)) return 0;
	}
	
	return 1;
}