#include <cstdio>
#include <string.h>

char input1[53], input2[53];
void input();

int main(){
	input();
	int allCount = 987654;
	int diff = strlen(input2) - strlen(input1);
	int small = strlen(input1);
	for(int i = 0; i <= diff; i++){
		int count = 0;
		for(int j = 0; j < small; j++){
			if(input1[j] != input2[i + j]){
				count++;
			}
		}
		if(allCount > count)
			allCount = count;
	}

	printf("%d", allCount);
}

void input(){
	scanf("%s %s", &input1, &input2);
}