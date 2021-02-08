#include <cstdio>
#include <queue>

#define ll long long
using namespace std;

priority_queue<ll, vector<ll>, greater<ll> > pq;

int main(){
	ll N, num;
	
	scanf("%lld", &N);
	ll origin = N;
	N *= N;

	for(int i = 0; i < N; i++){
		scanf("%lld", &num);
		if(pq.empty() || pq.size() < origin)
			pq.push(num);
		else if(pq.size() == origin){
			if(pq.top() < num){
				pq.pop();
				pq.push(num);
			}
		}
	}

	printf("%lld", pq.top());
}