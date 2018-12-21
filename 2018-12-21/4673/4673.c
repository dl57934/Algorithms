#include <stdio.h>

int main(){
	int selfNumber[100037] = {0,};
	int tou, hun, ten, one;
	int all;
	for(int i = 1;i <9994; i++){
		all = i;
		tou = all/1000;
		all -= tou * 1000;
		hun = all/100;
		all -= hun * 100;
		ten = all/10;
		one = all%10;
		selfNumber[i+tou+hun+ten+one] = -1;
	}

	for(int i = 1;i <9994; i++){
		if(selfNumber[i] != -1)
		printf("%d\n", i);
	}	

}