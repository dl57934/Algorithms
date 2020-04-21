#include <cstdio>
#include <algorithm>

using namespace std;

int num[1000002];
int N;
void backTrack();

void dp();

int main(){
	scanf("%d", &N);
	dp();
	printf("%d\n", num[N]);
	// printf("%d %d", num[9], num[5]);
	backTrack();
}

void dp(){
	num[1] = 0;
	num[2] = 1;
	num[3] = 1;
	for(int i = 4; i <= N; i++){
		if(i % 3 == 0){
			if(i % 2 == 0)
				num[i] = min(min(num[i-1], num[i/2]), num[i/3]) + 1;	
			else
				num[i] = min(num[i-1], num[i/3]) + 1;	
		}else if(i % 2 == 0){
			num[i] = min(num[i-1], num[i/2]) + 1;
		}else{
			num[i] = num[i-1] + 1;
		}
	}
}

void backTrack(){
	while(N > 0){
		if(N % 3 == 0){
			if(N % 2 == 0){
				if(num[N%3] > num[N%2]){
					if(num[N/2] > num[N-1]){
						printf("%d ", N);
						N-=1;
					}else{
						printf("%d ", N);
						N/=2;
					}		
				}else{
					if(num[N/3] > num[N-1]){
						printf("%d ", N);
						N-=1;
					}else{
						printf("%d ", N);
						N/=3;
					}
				}
			}else{
				if(num[N/3] > num[N-1]){
					printf("%d ", N);
					N-=1;
				}else{
					printf("%d ", N);
					N/=3;
				}
			}
		}else if(N % 2 == 0){
			if(num[N/2] >= num[N-1]){
					printf("%d ", N);
					N-=1;
				}else{
					printf("%d ", N);
					N/=2;
				}
		}else{
			printf("%d ", N);
			N-=1;
		}
	}
}