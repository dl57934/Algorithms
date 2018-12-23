#include <stdio.h>
#include <string.h>

int main(){
	int count = 0;
	char a[1000001];
	fgets(a, 1000001, stdin);
	
	for(int i = 1; i < strlen(a)-2;i++){
		if(a[i] == ' ')
			count++;
		}
		if(strlen(a)==2 && a[0]==' ')
			printf("0");
		else
			printf("%d",count+1);
}