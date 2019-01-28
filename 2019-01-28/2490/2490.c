#include <stdio.h>

int arr[4]={0,};

int main(){
	int cnt = 0;
	for(int i = 0; i < 3; i++){
		scanf("%d %d %d %d",&arr[0] ,&arr[1], &arr[2], &arr[3]);
		cnt = arr[0] + arr[1] + arr[2] + arr[3];
		if(cnt == 0)
			printf("D\n");
		else if(cnt == 1)
			printf("C\n");
		else if(cnt == 2)
			printf("B\n");
		else if(cnt == 3)
			printf("A\n");
		else if(cnt == 4)
			printf("E\n");
		cnt = 0;
	}
}