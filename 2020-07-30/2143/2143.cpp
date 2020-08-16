#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll T, A, B;
ll Aorigin[1002], Borigin[1002];
vector <ll> Asum, Bsum;


void input();

int main(){
	input();
	ll count = 0;
	for(auto a : Asum){
		ll findNum = T - a;
		ll upperNum = upper_bound(Bsum.begin(), Bsum.end(), findNum) - Bsum.begin();
		if(findNum == upperNum && T != a)
			count++;
	}

	printf("%lld", count);
}

void input(){
	scanf("%lld", &T);
	scanf("%lld", &A);
	for(int i = 0; i < A; i++)
		scanf("%lld", &Aorigin[i]);

	for(int i = 0; i < A; i++){
		Asum.push_back(Aorigin[i]);
		ll sub = Aorigin[i];
		for(int k = i+1; k < A; k++){
			sub += Aorigin[k];
			Asum.push_back(sub);
		}
	}

	scanf("%lld", &B);
	for(int i = 0; i < B; i++)
		scanf("%lld", &Borigin[i]);
	

	for(int i = 0; i < B; i++){
		Bsum.push_back(Borigin[i]);
		ll sub = Borigin[i];
		for(int k = i+1; k < B; k++){
			sub += Borigin[k];
			Bsum.push_back(sub);
		}
	}

	sort(Bsum.begin(), Bsum.end());
}