#include <stdio.h>

int main(){
	int T;
	int firstNum = 0, secondNum = 0;

	scanf("%d", &T);
	for(int i  = 1; i <= T; i++){
		scanf("%d %d", &firstNum, &secondNum);
		printf("Case #%d: %d + %d = %d\n", i, firstNum, secondNum, firstNum +secondNum);
	}
}