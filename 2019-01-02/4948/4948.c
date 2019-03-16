#include <stdio.h>
#include <math.h>

int count = 0;

void estoras(int num);
void turnel(int num);

int main(){
	int num;
	for(;;){
		scanf("%d", &num);
		if(num == 0)
			break;
		else 
			turnel(num);
	}
}

void turnel(int num){
	for(int i = num+1; i <= num*2; i++)
		estoras(i);
	printf("%d\n", count);
	count = 0;
}

void estoras(int num){
	for(int i = 2; i <= sqrt(num); i++)
		if(num % i == 0)
			return ;
	count++;	
}

