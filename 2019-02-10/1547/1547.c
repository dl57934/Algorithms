#include <stdio.h>

int cups[4] = {0, };

void swap(int a, int b);

int main(){
	cups[0] = 1;
	int M=0, from=0, to=0;
	scanf("%d", &M);
	for(int i = 0 ; i < M; i++){
		scanf("%d %d", &from, &to);
		swap(from-1, to-1);
	}
	for(int i = 0; i < 3; i++)
		if(cups[i] == 1)
			printf("%d", i+1);
}

void swap(int a, int b){
	int temp = cups[a];
	cups[a] = cups[b];
	cups[b] = temp;
}