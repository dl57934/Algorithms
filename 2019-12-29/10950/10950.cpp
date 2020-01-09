#include <stdio.h>

int main(){
	int T=0;
	int firstNum, secondNum;

	scanf("%d", &T);

	for(int i = 0; i<T; i++){
		scanf("%d %d", &firstNum, &secondNum);
		printf("%d\n", firstNum+secondNum);
	}		
}