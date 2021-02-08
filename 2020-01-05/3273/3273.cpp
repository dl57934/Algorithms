#include <cstdio>
#include <algorithm>

using namespace std;

void TwoPointer();

int N, X;
int number[100002];

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &number[i]);
	}

	scanf("%d", &X);

	sort(number, number + N);

	TwoPointer();
}

void TwoPointer(){
	int start = 0, end = N-1;
	int count = 0;

	while(start < end){
		if(X == number[start] + number[end]){
			start++, end--, count++; 
		}else if(X > number[start] + number[end]){
			start++;
		}else{
			end--;
		}
	}

	printf("%d", count);
}

// 1 2 3 5 7 9 10 11 12