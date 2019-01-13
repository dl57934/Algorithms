// #include <stdio.h>

// #define M_PI 3.14159265358979

// int main(){
// 	double R;
// 	scanf("%lf", &R);
// 	double uclid = R*R*M_PI;
// 	double taxi = R*R*2;
// 	printf("%.6f\n", uclid);
// 	printf("%.6f", taxi);
// }

#include <stdio.h>

#define M_PI 3.14159265358979

int main(){
	int R;
	scanf("%d", &R);
	float uclid = R*R*M_PI;
	float taxi = ((float)(R*R)/2)*4;
	printf("%.6f\n", uclid);
	printf("%.6f", taxi);
}