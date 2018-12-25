#include <stdio.h>


int main(){
	char arr[102] = {};

	fgets(arr, 102, stdin);

	for (int i = 0; i<100; i++){
		if(arr[i] == '\n') break;
		printf("%c", arr[i]);
		if(i % 10 == 9)
		printf("\n");
	}
}