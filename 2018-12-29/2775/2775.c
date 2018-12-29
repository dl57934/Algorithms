#include <stdio.h>

void setMember();

int arr[16][16];

int main(T){
	int k, n;
	setMember();
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", arr[k][n]);
	}

}




void setMember(){
	for(int i = 0; i <16; i ++){
		for(int j = 0; j < 16; j++){

			if(i == 0)
				arr[i][j] = j;

			else if(j == 1)
				arr[i][j] = 1;

			else
				arr[i][j] = arr[i][j-1] + arr[i-1][j];
		}
	}
}