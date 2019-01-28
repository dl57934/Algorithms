#include <cstdio>

long long pisano(int M);


int main(){
	int P, N, M;
	scanf("%d", &P);
	for(int i = 0; i < P; i ++){
		scanf("%d %d", &N, &M);
		printf("%d %lld\n",N ,pisano(M));
	}
}

long long pisano(int M){
	int one = 1;
	int two = 1;
	long long count = 0;
	while(1){
		int temp = two;
		two = (one + two)%M;
		one = temp;
		count+=1;
		if(one==1 && two==1)
			break;
	} 
	
	return count;
}
