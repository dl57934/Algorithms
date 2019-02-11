#include <stdio.h>

int main(){
	int N;
	int canPlug=0;
	int multi[500003];
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &multi[i]);
		if(canPlug!=0)
			canPlug+=(multi[i]-1);
		else 
			canPlug+=multi[i];
	}	
	printf("%d", canPlug);
}