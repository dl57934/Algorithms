#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int N;
typedef long long ll;
int arrIndex;
vector<ll> arr;

void input();

int main(){
	input();
	printf("%d", arr.size());
}

void input(){
	ll num;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%lld", &num);
		if(arr.size() == 0){
			arr.push_back(num);
		}else if(arr.back() < num){
			arr.push_back(num);
		}else{
			int index = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
			arr[index] = num;
		}
	}
}