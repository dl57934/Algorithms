#include <stdio.h>
#include <math.h>
int main(){
	int x, y, w, h;
	int minx=0, miny=0;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	if(w-x > x)
		minx=x;
	else
		minx=w-x;
	if(h-y > y)
		miny = y;
	else
		miny = h-y;
	if(minx > miny)
		printf("%d", miny);
	else
		printf("%d", minx);
}