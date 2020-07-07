#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
void input();
void calculate();
vector<int> packagePrice, soloPrice;

int main(){
	input();
	calculate();
}

void input(){
	scanf("%d %d", &N, &M);
	int setPrice, onePrice;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &setPrice, &onePrice);
		packagePrice.push_back(setPrice), soloPrice.push_back(onePrice);
	}
	sort(packagePrice.begin(), packagePrice.end());
	sort(soloPrice.begin(), soloPrice.end());
}

void calculate(){
	int pack = packagePrice[0];
	int solo = soloPrice[0];

	int price1 = (N/6) * pack;
	price1+=(N%6) * solo > pack ? (N%6) == 0 ? 0:pack: (N%6) * solo;
	int price2 = N*solo;
	if(price1 > price2)
		printf("%d", price2);
	else
		printf("%d", price1);
}