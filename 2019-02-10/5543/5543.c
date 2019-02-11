#include <stdio.h>

int main(){
	int foods[5];
	int minDrink;
	int min = 10000;
	for(int i = 0; i < 5; i++)
		scanf("%d", &foods[i]);
	if(foods[3] < foods[4])
		minDrink=foods[3];
	else
		minDrink=foods[4];	

	for(int i =0; i < 3; i++){
		if(minDrink+foods[i] < min)
			min=minDrink+foods[i];
	}
	printf("%d", min-50);
}