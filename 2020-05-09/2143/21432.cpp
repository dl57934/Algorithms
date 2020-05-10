#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

#define ll long long

using namespace std;

ll A[1003], B[1003];
ll T;
int aSize, bSize;
vector<ll> aSum;
vector<ll> bSum;

ll twoPoint();
void getSomeSum();
void input();

int main(){
	input();
	getSomeSum();
	printf("%lld", twoPoint());
}

void getSomeSum(){
	ll sum = 0;
	for(int i = 0; i < aSize; i++){
			sum = A[i];
			aSum.push_back(sum);
		for(int j = i+1; j < aSize; j++){
			sum += A[j];
			aSum.push_back(sum);
		}
	}

	for(int i = 0; i < bSize; i++){	
			sum = B[i];
			bSum.push_back(sum);
		for(int j = i+1; j < bSize; j++){
			sum += B[j];
			bSum.push_back(sum);
		}
	}
	sort(aSum.begin(), aSum.end());
	sort(bSum.begin(), bSum.end());
}

void input(){
	scanf("%lld", &T);
	scanf("%d", &aSize);
	for(int i = 0; i < aSize; i++){
		scanf("%lld", &A[i]);
	}
	scanf("%d", &bSize);
	for(int i = 0; i < bSize; i++){
		scanf("%lld", &B[i]);
	}
}	

ll twoPoint(){
	long long start = 0, end = bSum.size()-1;
	long long count = 0;
	while(start < aSum.size() && end >= 0){
		if(aSum[start] + bSum[end] == T){
			long long leftCount = 1, rightCount = 1;
			while(start + leftCount < aSum.size() && aSum[start] == aSum[start + leftCount])
				leftCount+=1;
			while( end-rightCount >= 0 && bSum[end] == bSum[end-rightCount])
				rightCount+=1;
			count += leftCount * rightCount;
			start = start + leftCount;
			end = end - rightCount;
		}else if(aSum[start] + bSum[end] < T){
			start++;
		}else if(aSum[start] + bSum[end] > T){
			end--;
		}
	}
	return count;
}