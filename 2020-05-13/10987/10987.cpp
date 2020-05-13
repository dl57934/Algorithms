#include <cstdio>
#include <string.h>

char order[200];

int main(){
	scanf("%s", &order);
	int size = strlen(order);
	int result = 0;
	for(int i = 0; i < size; i++)
		if(order[i] == 'a' || order[i] == 'u' || order[i] == 'o' || order[i] == 'i' || order[i] == 'e')
			result += 1;

	printf("%d", result);
}