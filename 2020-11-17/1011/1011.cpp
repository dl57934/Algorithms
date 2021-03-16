#include <cstdio>
#include <vector>
#define ll long long

using namespace std;

vector<int> movePoint;

int main(){
	ll T, x, y;
	scanf("%lld", &T);

	for(int i = 0; i < T; i++){
		scanf("%lld %lld", &x, &y);
		ll move = 1, count = 0;
		ll start = x, desination = y;

		while(1){
			ll diff = desination - start;
			if(start >= desination){	
				printf("%lld\n", count);
				break;
			}else if(move >= diff){
				printf("%lld\n", count+1);
				break;
			}

			start+= move, desination -= move;
			count += 2, move += 1;
		}
	}
}