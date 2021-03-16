#include <cstdio>
#include <string.h>

int time[9] = {3, 4, 5, 6, 7, 8, 9, 10};
char order[17];
int count = 0;

int main(){
	scanf("%s", &order);
	int orderLength = strlen(order);

	for(int i = 0; i < orderLength; i++){
		if(order[i] >= 'A' && order[i] <= 'C'){
			count += time[0];
		}else if(order[i] >= 'D' && order[i] <= 'F'){
			count += time[1];
		}else if(order[i] >= 'G' && order[i] <= 'I'){
			count += time[2];
		}else if(order[i] >= 'J' && order[i] <= 'L'){
			count += time[3];
		}else if(order[i] >= 'M' && order[i] <= 'O'){
			count += time[4];
		}else if(order[i] >= 'P' && order[i] <= 'S'){
			count += time[5];
		}else if(order[i] >= 'T' && order[i] <= 'V'){
			count += time[6];
		}else if(order[i] >= 'W' && order[i] <= 'Z'){
			count += time[7];
		}
	}

	printf("%d", count);
}