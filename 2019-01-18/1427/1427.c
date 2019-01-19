#include <stdio.h>

int arr[11]={0,};

int main(){
	char N;
	while(1){
		N = getchar();
		if(N=='\n')
			break;
		arr[N-'0']+=1;
	}

	for(int i = 9; i >= 0; i--){
		for(int k =0; k < arr[i]; k++)
			printf("%d", i);
	}
}