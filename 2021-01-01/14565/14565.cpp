#include <cstdio>
#include <vector>

using namespace std;

#define ll long long

ll gcd(ll a, ll b);
ll xGCD(ll a, ll b);

int main(){
	ll a, b;
	scanf("%lld %lld", &a, &b);

	printf("%lld ", a - b);
	if(gcd(a, b) != 1){
		printf("-1");
		return 0;
	}
	ll result = xGCD(a, b);
	
	if(result < 0)
		result += a;
	printf("%lld", result);
}

vector <ll> q;
vector <ll> r;
vector <ll> s;
vector <ll> t;

ll gcd(ll a, ll b){
	if( b == 0)
		return a;
	return gcd(b, a%b);
}

ll xGCD(ll a, ll b){
	r.push_back(a);
	r.push_back(b);
	s.push_back(1);
	s.push_back(0);
	t.push_back(0);
	t.push_back(1);

	while(1){
		ll r1 = r[r.size() - 1];
		ll r2 = r[r.size() - 2];
		q.push_back(r2/r1);
		r.push_back(r2%r1);

		if(r[r.size() - 1] == 0){

			return t[t.size()-1]  < 0? t[t.size()-1] + a : t[t.size()-1];
		}

		ll s2 = s[s.size() - 2];
		ll s1 = s[s.size() - 1];

		ll t2 = t[t.size() - 2];
		ll t1 = t[t.size() - 1];

		ll qnum = q[q.size()-1];

		s.push_back(s2 - s1 * qnum);
		t.push_back(t2 - t1 * qnum);
	}

	q.clear();
	s.clear();
	r.clear();
	t.clear();
}