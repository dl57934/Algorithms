#include <stdio.h>

int N;

void makeRecursion(int n);
void makeStar(int n);

int main(){
	scanf("%d", &N);
	makeStar(N);
}


void makeRecursion(int n){
	makeStar(n);
}

void makeStar(int n){
	printf("*");
	printf("* *");
	printf("*****");
}