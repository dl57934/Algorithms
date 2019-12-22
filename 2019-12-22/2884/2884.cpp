#include <stdio.h>

int main(){
	int hour, minute;

	scanf("%d %d", &hour, &minute);

	minute-=45;

	if(minute<0){
		hour-=1;
		minute = 60 + minute;
		if(hour<0)
			hour=23;
	}

	printf("%d %d", hour, minute);

}