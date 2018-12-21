#include <stdio.h>

main(N){
	float score[1001] = {0,}; 
	float M = 0.0;
	float result = 0.0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%f", &score[i]);
		if(score[i] > M)
			M = score[i];
	}

	for (int i = 0; i<N; i++)
		result += score[i]/ M * 100;
	printf("%.2f", result/N);
}