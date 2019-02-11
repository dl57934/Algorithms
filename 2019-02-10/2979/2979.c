#include <stdio.h>

typedef struct _parkingTime{
	int start;
	int end;
}parkingTime;

parkingTime time[4];

int main(){
	int price[4];
	price[0] = 0;
	int totalPrice = 0;
	scanf("%d %d %d", &price[1], &price[2], &price[3]);

	for(int i = 1; i < 4; i++){
		scanf("%d %d", &time[i].start, &time[i].end);
		time[i].end-=1;
	}
	
	for(int i = 1; i <= 100; i++){
		int selectedCar = 0;
		for (int car = 1; car <= 3; car++)
			if( time[car].start <= i && time[car].end >= i)
				selectedCar += 1;
		
		totalPrice+=price[selectedCar]*selectedCar; 
	}
	printf("%d", totalPrice);
}

