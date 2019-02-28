#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[10300000];
vector <ll>result;

int getGCD(int A, int B);
void mergesort(int start, int end);
void merge(int start, int mid, int end);
void getDivisor(int gcd);

int main (){
	int N;
	scanf("%d", &N);
	int count = N;
	for(int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);

	mergesort(0, N-1);
	int gcd = arr[1] - arr[0];
	for(int i = 2; i < N; i++)
		gcd = getGCD(gcd, arr[i] - arr[i-1]);
	
	mergesort(0, N-2);	
	getDivisor(gcd);
}

void getDivisor(int gcd){
	int count = 0;
	for(int i = 2; i*i <= gcd; i++){
		if(gcd%i ==0){
			if( i == gcd/i){
				result.push_back(i);
			}	
			else {
				result.push_back(i);
				result.push_back(gcd/i);
			}
			count++;
		}	
	}
	result.push_back(gcd);
	sort(result.begin(), result.end());

	for(int i = 0; i < result.size(); i++){
		printf("%lld ", result[i]);
	}
}

int getGCD(int A, int B){
	if(B==0)
		return A;
	return getGCD(B, A%B);
}

void mergesort(int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		mergesort(start, mid);
		mergesort(mid+1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end){
	int temp [104];
	for(int i =start; i <= end; i++)
		temp[i] = arr[i];

	int index = start; 
	int part1=start, part2 = mid+1;

	while(part1 <= mid && part2 <=end){
		if(temp[part1] < temp[part2]){
			arr[index] = temp[part1];
			part1++;
		}else{
			arr[index] = temp[part2];
			part2++;
		}
		index++;
	}
	for(int i = 0; i <= mid-part1; i++)
		arr[i+index] = temp[part1+i];
}



