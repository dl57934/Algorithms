// #include <cstdio>
// #include <math.h>
// #include <map>
// #include <string>
// #include <algorithm>

// #define ll long long

// using namespace std;

// ll A[1003], B[1003];
// ll T;
// int aSize, bSize;
// map <ll, ll> aMap;
// map <ll, ll> bMap;

// void getSomeSum();
// void input();

// int main(){
// 	long long count = 0;
// 	input();
// 	getSomeSum();
// }

// void getSomeSum(){
// 	ll sum = 0;
// 	ll count = 0;
// 	for(int i = 0; i < aSize; i++){
// 			sum = A[i];
// 			aMap[sum] += 1;
// 		for(int j = i+1; j < aSize; j++){
// 			sum += A[j];
// 			aMap[sum] += 1;
// 		}
// 	}

// 	for(int i = 0; i < bSize; i++){	
// 			sum = B[i];
// 			if(abs(sum) <= 1000000000)
// 				count+=aMap[T-sum];
// 		for(int j = i+1; j < bSize; j++){
// 			sum += B[j];
// 			if(abs(sum) <= 1000000000)
// 				count+=aMap[T-sum];
// 		}
// 	}
// 	printf("%lld", count);
// }

// void input(){
// 	scanf("%lld", &T);
// 	scanf("%d", &aSize);
// 	for(int i = 0; i < aSize; i++){
// 		scanf("%lld", &A[i]);
// 	}
// 	scanf("%d", &bSize);
// 	for(int i = 0; i < bSize; i++){
// 		scanf("%lld", &B[i]);
// 	}
// }	