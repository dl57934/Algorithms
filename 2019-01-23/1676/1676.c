#include <stdio.h>

int main(){
	int N;
	int two=0, five=0;
	int saveNum;
	scanf("%d", &N);

	for(int i = 5; i <= N; i++){
		if(i%5==0){
			saveNum = i;
			while(saveNum%5==0){
				saveNum/=5;
				five+=1;
			}
		}
	}
	printf("%d", five);
}