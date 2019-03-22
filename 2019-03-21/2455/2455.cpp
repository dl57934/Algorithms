#include <cstdio>

int out[4];
int in[4];

int max = 0;
int sum = 0;
int main(){
	for(int i =0; i < 4; i++)
		scanf("%d %d", &out[i], &in[i]);

	for(int i = 0; i < 4; i++){
		sum += in[i]-out[i];
		if(max < sum)
			max = sum;
		
	}
	printf("%d", max);
}