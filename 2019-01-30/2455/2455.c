#include <stdio.h>

int main(){
	int dropper, upper;
	int max = 0, saveNum=0;
	for(int i = 0; i < 4; i++){
		scanf("%d %d", &dropper, &upper);	
		saveNum = saveNum-dropper+upper;
		if(max < saveNum)
			max = saveNum;
	}
	printf("%d", max);
}