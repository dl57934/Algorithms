#include <stdio.h>

int isLeapYear(int year);

int main(){
	int year;
	scanf("%d", &year);

	if(isLeapYear(year))
		printf("1");
	else 
		printf("0");
}


int isLeapYear(int year){
	return !(year%4) && (year%100 || !(year%400));
}