#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

ll target, n, m;
ll A[1002], B[1002];
vector<ll> ASum, BSum;

void input();
void setSum();

int main(){
	input();
	setSum();
	ll result = 0;
	for(auto a : ASum){
		ll t = target - a;
		int startIndex = lower_bound(BSum.begin(), BSum.end(), t) - BSum.begin();
		int endIndex = upper_bound(BSum.begin(), BSum.end(), t) - BSum.begin();
		result+= endIndex-startIndex;
	}

	printf("%lld", result);
}

void input(){
	scanf("%lld %lld", &target, &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", &A[i]);

	scanf("%lld", &m);

	for(int i = 0; i < m; i++)
		scanf("%lld", &B[i]);
}

void setSum(){
	for(int origin = 0; origin < n; origin++){
		ll subSum = A[origin];
		ASum.push_back(subSum);
		for(int sub = origin+1; sub < n; sub++){
			subSum+=A[sub];
			ASum.push_back(subSum);
		}
	}

	for(int origin = 0; origin < m; origin++){
		ll subSum = B[origin];
		BSum.push_back(subSum);
		for(int sub = origin+1; sub < m; sub++){
			subSum+=B[sub];
			BSum.push_back(subSum);
		}
	}

	sort(BSum.begin(), BSum.end());
}