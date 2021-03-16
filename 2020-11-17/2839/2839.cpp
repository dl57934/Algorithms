#include <cstdio>

int sugar[5002];

int main(){
	int N;
	scanf("%d", &N)	;

	sugar[1] = -1, sugar[2] = -1, sugar[3] = 1;
	sugar[4] = -1, sugar[5] = 1;

	for(int i = 6; i <= N; i++){
		if(sugar[i-3] != -1){
			sugar[i] = sugar[i-3] + 1;
			if(sugar[i-5] != -1 && sugar[i] > sugar[i-5] + 1)
				sugar[i] = sugar[i-5] + 1;
		}else if(sugar[i-5] != -1)
			sugar[i] = sugar[i-5] + 1;
		else
			sugar[i] = -1;

	}
	
	printf("%d", sugar[N]);
}