#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;

ll maxLength = 0;
ll trees[1000003];

ll N, M;

void binarySearch(ll startLength, ll endLength, ll limit);

int main(){
	
	scanf("%lld %lld", &N, &M);

	for(int i = 0; i < N; i++)
		scanf("%lld", &trees[i]);

	binarySearch(1, *max_element(trees, trees + N), M);

	printf("%lld", maxLength);
}


void binarySearch(ll startLength, ll endLength, ll limit){
	if(startLength > endLength)
		return ;
	ll midLength = (startLength+endLength)/2;
	ll temp = 0;

	for(int i = 0; i < N; i++){
		if(trees[i] - midLength>0)
			temp+=(trees[i] - midLength);
	}


	if(temp >= limit && midLength > maxLength){
		maxLength = midLength;
		binarySearch(midLength+1, endLength, limit);
	}else if(temp < limit){
		binarySearch(startLength, midLength-1, limit);
	}
	
}