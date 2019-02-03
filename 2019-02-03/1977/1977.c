#include <stdio.h>

int main(){
	int M, N;
	int save=0, min=0;
	scanf("%d %d",&M, &N);
	for(int i = 1; i<=100; i++){
		if(M<=i*i && N>=i*i){
			if(min == 0)
				min=i*i;
			save+=i*i;
		}else if(N<i*i)
			break;
	}
	if (save==0)
		printf("-1");
	else
		printf("%d\n%d",save,min);
}