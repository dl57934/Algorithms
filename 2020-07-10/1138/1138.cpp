#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int vc[12];
int order[12];
int N;

void input();

int main(){
	input();

	for(int i = 0; i < N; i++)
		printf("%d ", vc[i]);
}

void input(){
	int number;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &number);
		order[i] = number;
	}

	reverse(order, order+N);

	for(int i = 0; i < N; i++){
		if(vc[order[i]] == 0){
			vc[order[i]] = N-i;
		}else{
			for(int j = N-2; j >= order[i]; j--){
				vc[j+1] = vc[j];	
			}
			vc[order[i]] = N-i;
		}
	}
}