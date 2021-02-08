#include <cstdio>

long long map[202][202]; // 되고 싶은 숫자, 선택한 개수

int main(){
	int N, K;
	long long save = 0;
	scanf("%d %d", &N, &K);

	map[0][1] = 1;
	map[1][1] = 1, map[1][2] = 2;
	map[2][1] = 1, map[2][2] = 3;
	
	for(int wantNum = 3; wantNum <= N; wantNum++){
		map[wantNum][1] = 1;
		for(int select = 2; select <= K; select++){
			int limit =  wantNum % 2 ==0? wantNum/2 : wantNum/2 + 1;
			for(int minus = 0; minus <= limit; minus++){
				if(wantNum % 2 == 0 && minus == limit){
					map[wantNum][select] += map[wantNum-minus][select-1]%1000000000;
				}else{
					map[wantNum][select] += (map[wantNum-minus][select-1]*2)%1000000000;
				}
				
				map[wantNum][select] %= 1000000000;
			}
		}
	}

	printf("%lld", map[N][K]%1000000000);
}