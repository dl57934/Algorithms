#include <cstdio>

int main(){
	int X;
	int floor = 1;
	scanf("%d", &X);

	while(X - floor > 0){
		X-=floor;
		floor+=1;
	}

	if(floor % 2 == 0)
		printf("%d/%d", X, floor-X + 1);
	else
		printf("%d/%d", floor-X + 1, X);
}