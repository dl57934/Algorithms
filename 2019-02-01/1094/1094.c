#include <stdio.h>

int main(){
	int save=64, entire = 64;
	int X, stick=1;
	scanf("%d", &X);
	while(entire!=X){
		if(X < entire){
			save/=2;
			stick+=1;
			if(entire-save>=X){
				entire-=save;
				stick-=1;
			}
		}
	}
	printf("%d", stick);
}