#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 
int main(){
	int arr[10] = {0,};
	int A, B, C;
	int oneNum=0, startNum;
	int lastNum=0;
	scanf("%d\n%d\n%d", &A, &B, &C);
	int all = A*B*C;
	for(int i = 100000000; i>=1; i/=10){
		if(all>=i){
			startNum = i;
			break;
		}
	}

	for(int i = startNum; i>=1; i/=10){
			oneNum = all/i;
			arr[oneNum] +=1;
			all-=oneNum*i;
	}

	for(int i =0;i<10;i++)
		printf("%d\n", arr[i]);
	
}
