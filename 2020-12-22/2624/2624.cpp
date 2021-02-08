#include <cstdio>
#include <vector>

using namespace std;
vector<pair<int, int> > vc;

int main(){
	int T, k, coin, number;

	scanf("%d %d", &T, &k);

	for(int i = 0; i < k; i++){
		scanf("%d %d", &coin, &k);
		vc.push_back(make_pair(coin, k));
	}
}