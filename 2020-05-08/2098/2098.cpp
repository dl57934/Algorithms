#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[18][18], cache[18][987654];
int travel(int city, int mask);
int check(int city, int mask);
int allCheck(int mask);
vector<int> costMerge;
void input();

int main(){
	input();
	
	printf("%d", travel(1, 0));
}

void input(){
	scanf("%d", &N);
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			scanf("%d", &map[y][x]);
		}
	}
}

int travel(int city, int mask){
	mask |= 1 << (city-1);

	if(allCheck(mask)){
		if(map[city][1] > 0)
			return map[city][1];
		else
			return 987654321;
	}
	
	if(cache[city][mask])
		return cache[city][mask];
		
	int ret = 987654321;
	for(int nextCity = 1; nextCity <= N; nextCity++){
		if(map[city][nextCity] && check(nextCity-1, mask)){
			int temp = travel(nextCity, mask | (1 << (nextCity-1))) + map[city][nextCity];
			if(ret > temp)
				ret = temp;
		}
	}
	cache[city][mask] = ret;
	return cache[city][mask];
}

int allCheck(int mask){
	int all = (1 << N) - 1;
	if(mask == all)
		return 1;
	else return 0;
}

int check(int city, int mask){
	if( (mask & (1 << city)))
		return 0;
	else 
		return 1;
}