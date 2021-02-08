#include <cstdio>
#include <vector>
#include <stdlib.h>
using namespace std;

int length, N;
vector<char> vc[12], orders(12), vcInteger[12];

int isValidOrder(int num, int limit);
void backTrack(int limit);

int main(){
	
	scanf("%d", &N);
	length = N * (N + 1);
	length/=2;

	for(int i = 0; i <= 10; i++){
		vc[i].assign(5050, 0);
		vcInteger[i].assign(5050, 0);
		orders[i] = 0;
	}

	int layer = 0, layerLimit = N, count = 0;
	char order;
	for(int i = 0; i < length; i++){
		scanf(" %c", &order);
		vc[layer][count] = order;
		count ++;
		if(layerLimit == count){
			layer+=1;
			count=layer;
		}
	}

	backTrack(0);
}

void backTrack(int limit){
	if(limit == N){
		for(int i = 0; i < limit; i++)
			printf("%d ", orders[i]);
		exit(0);
	}

	for(int i = -10; i <= 10; i++){
		if(isValidOrder(i, limit)){
			orders[limit] = i;
			backTrack(limit + 1);
		}
	}
}

int isValidOrder(int num, int limit){
	for(int i = 0; i <= limit; i++){

		if(i == limit){
			if(vc[i][limit] == '-' && num < 0){
				vcInteger[i][limit] = num;
			}
			else if(vc[i][limit] == '+' && num > 0){
				vcInteger[i][limit] = num;
			}
			else if(vc[i][limit] == '0' && num == 0){
				vcInteger[i][limit] = 0;
			}else {
				return 0;
			}
		}else{
			if(vc[i][limit] == '-' && vcInteger[i][limit-1] + num < 0){
				vcInteger[i][limit] = vcInteger[i][limit-1] + num;
			}else if(vc[i][limit] == '+' && vcInteger[i][limit-1] + num > 0){
				vcInteger[i][limit] = vcInteger[i][limit-1] + num;
			}else if(vc[i][limit] == '0' && vcInteger[i][limit-1] + num == 0){
				vcInteger[i][limit] = 0;
			}else {
				return 0;
			}
		} 
	}
	return 1;
}