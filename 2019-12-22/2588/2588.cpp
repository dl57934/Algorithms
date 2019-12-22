#include <cstdio>

void getReminder(int numbers, int divide, int idx);
int saver[10];

int main(){
	int firstNumber = 0, secondNumber = 0;

	scanf("%d", &firstNumber);
	scanf("%d", &secondNumber);

	getReminder(secondNumber, 100, 2);

	for (int i = 0; i < 3; i++)
		printf("%d\n", firstNumber*saver[i]);
	printf("%d\n", firstNumber*secondNumber);
}

void getReminder(int numbers, int divide, int idx){
	int share = numbers/divide;
	saver[idx] = share;
	numbers -= share*divide;
	if(divide==10){
		saver[--idx] = numbers;
		return ;
	}
	getReminder(numbers, divide/10, idx-1);
}