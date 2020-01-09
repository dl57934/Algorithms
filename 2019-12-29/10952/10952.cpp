#include <stdio.h>

int main(){
	int firstNum=1, secondNum=1;

	while(firstNum!=0 && secondNum!=0){
		scanf("%d %d", &firstNum, &secondNum);
		if(firstNum!=0 && secondNum!=0)
			printf("%d\n", firstNum+secondNum);
	}
}