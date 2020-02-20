#include <cstdio>

long long N, B;
long long arr[10][10];
long long temp[10][10];
long long result[10][10];

void moveToResult();
void mul();
void input();
void calculator(int insert);
void resultMul();

int main(){
	int firstTime = 1;
	scanf("%lld %lld", &N, &B);
	input();

	if(B == 1)
		moveToResult();

	while(B!=1){
		int isMul = B%2;
		B/=2;
		if(isMul && firstTime){
			moveToResult();
			mul();
			firstTime = 0;
		}
		else {
			if(isMul)
				resultMul();
			mul();	
		}

		if(B==1){
			if(firstTime)
				moveToResult();
			else
				resultMul();
		}
	}	

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%lld ", result[i][j]);
		}
		printf("\n");
	}
}

void input(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%lld", &arr[i][j]);
}

void mul(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			long long sum = 0;
			for(int k = 0; k < N; k++){
				sum += (arr[i][k] * arr[k][j]) % 1000;
				sum %=1000;
			}
			temp[i][j] = sum;
		}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			arr[i][j] = temp[i][j];
			temp[i][j] = 0;
		}
}

void resultMul(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			long long sum = 0;
			for(int k = 0; k < N; k++){
				sum += (result[i][k] * arr[k][j]) % 1000;
				sum %=1000;
			}
			temp[i][j] = sum;
		}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			result[i][j] = temp[i][j];
			temp[i][j] = 0;
		}
}

void moveToResult(){
	for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				result[i][j] = arr[i][j]%1000;
}