#include <cstdio>
#define ll long long

ll distance[100002], point[100002];

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N-1; i++)
		scanf("%lld", &distance[i]);

	for(int i = 0; i < N; i++)
		scanf("%lld", &point[i]);
	
	ll baseNumber = point[0];
	ll subDistance = distance[0];
	ll result = 0;

	for(int i = 1; i < N; i++){
		if(point[i] <= baseNumber){
			result += baseNumber * subDistance;
			baseNumber = point[i];
			subDistance = distance[i];
		}else{
			subDistance+=distance[i];
		}
	}

	if(subDistance != 0){
		result+= baseNumber * subDistance;
	}

	printf("%lld", result);
}	