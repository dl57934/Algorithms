#include <stdio.h>
#include <math.h>

int kyu[3], hwan[3]; // x, y, r

void checkSamePoint(double d, double r1, double r2);

int main(){
	int T = 0;
	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		scanf("%d %d %d %d %d %d", &kyu[0], &kyu[1], &kyu[2], &hwan[0], &hwan[1], &hwan[2]);

		if(kyu[0] == hwan[0] && kyu[1] == hwan[1] && kyu[2] == hwan[2])
			printf("-1\n");
		else{
			double d = pow(kyu[0]-hwan[0], 2)  + pow(kyu[1]-hwan[1], 2);
			checkSamePoint(d, kyu[2], hwan[2]);
		}
	}
}

void checkSamePoint(double d, double r1, double r2){
	if(pow(r1 - r2, 2) < d && d < pow(r1+r2, 2))
		printf("2\n");
	else if(pow(r1 + r2, 2) == d || pow(r1 - r2, 2) == d)
		printf("1\n");
	else if( d == 0 || pow(r1+r2, 2) < d || pow(r1-r2, 2)>d)
		printf("0\n");
}