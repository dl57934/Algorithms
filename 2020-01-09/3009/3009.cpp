#include <cstdio>

int n, m, x, y;

int main(){
	for(int i = 0 ; i < 3; i++){
		scanf("%d %d", &n, &m);
		x^=n;
		y^=m;		
	}

	printf("%d %d\n", x, y);

}