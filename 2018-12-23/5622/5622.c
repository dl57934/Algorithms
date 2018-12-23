#include <stdio.h>
#include <string.h>

int main(){
	char dial[16];
	int result = 0;
	int timer[8] = {3,4,5,6,7,8,9,10};
	scanf("%s", &dial);
	int length = strlen(dial);
	for(int i = 0; i < length; i++){
		if((dial[i] >='P' && dial[i] <='S'))
			result += timer[5];
		else if((dial[i] >='W' && dial[i] <='Z'))
			result += timer[7];
		else if((dial[i] >='T' && dial[i] <='V'))
			result += timer[6];
		else
			result += timer[dial[i]%65/3];
	}
	printf("%d", result);
}