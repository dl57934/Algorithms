#include <stdio.h>
#include <math.h>

double kyu[3], hwan[3]; // x, y, r

int checkSamePoint(double d, double r1, double r2);

int main(){
	int T = 0;
	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		scanf("%lf %lf %lf %lf %lf %lf", &kyu[0], &kyu[1], &kyu[2], &hwan[0], &hwan[1], &hwan[2]);

		if(kyu[0] == hwan[0] && kyu[1] == hwan[1] && kyu[2] == hwan[2])
			printf("-1\n");
		double d = sqrt(pow(kyu[0]-hwan[0], 2)  + pow(kyu[1]-hwan[1], 2));


	}
}

int checkSamePoint(double d, double r1, double r2){
	if(abs(r1 - r2) < d && d < abs(r1+r2))
		printf("2\n");
	else if(abs(r1 + r2) == d && abs(r1 - r2) == d)
		printf("1\n");
	else 
		printf("0\n");
}