#include <stdio.h>

void changeNum(int *M, int *N);
int LCM(int M, int N, int GSD);
int GSD(int M, int N);

int main(T){
	int M, N, X, Y;
	int foundX, size;
	int between = 0;
	scanf("%d", &T);
	int count;
	int gsd;
	for(int i = 0; i < T; i++){
		scanf("%d %d %d %d", &M, &N, &X, &Y);
		if (M < N){
			changeNum(&M, &N);
			changeNum(&X, &Y);
		}
		
		gsd = GSD(M, N);
		size = LCM(M, N, gsd);
		foundX = Y;
		count = Y;
		between = M-N;

		for (int i = 0; i <size; i+=N){
			if(foundX > M)
				foundX -= M;
			if(foundX == X){
				printf("%d\n", count);
				break;
			}else if(count+N > size){
				printf("-1\n");
				break;
			}

			foundX += N;
			count+=N;
		}
	}	
}

void changeNum(int *M, int *N){
	int temp;

		temp = *N;
		*N = *M;
		*M = temp;
}

int LCM(int M, int N, int GSD){
	return (M*N)/GSD;
}

int GSD(int M, int N){
	if (N == 0)
		return M;
	return GSD(N, M%N);
}




