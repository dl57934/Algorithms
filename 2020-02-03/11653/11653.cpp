#include <cstdio>

int main(){
	int N;
	scanf("%d", &N);
	int i = 2;
	for (;;){	
		if(N == 1)
			break;
		if(N%i == 0){
			N/=i;
			printf("%d\n", i);
			i=2;
		}
		else
			i+=1;
	}
}
