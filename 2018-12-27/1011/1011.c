#include <stdio.h>

int main(T){
	int count=0, distance = 1;
	int startPoint, destination; 
	int difference;
	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		scanf("%d %d", &startPoint, &destination);
		distance = 1;
		if(startPoint > 0)
			destination-=startPoint,startPoint-=startPoint;
		for (;;){
			difference = destination-startPoint;
			if(startPoint>=destination){
				printf("%d\n", count);
				break;
			}else if(difference <= distance){
				printf("%d\n", count+1);
				break;
			}
			startPoint+=distance, destination-=distance;
			count+=2;
			distance+=1;
		}
		count = 0;
	}
}