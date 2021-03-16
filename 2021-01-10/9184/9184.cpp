#include <cstdio>

int memo[102][102][102];

int dp(int a, int b, int c);

int a, b, c;

int main(){
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		if( a == -1 && b == -1 && c == -1)
			return 0;

		printf("w(%d, %d, %d) = %d\n", a, b, c, dp(a, b, c));
	}
}

int dp(int a, int b, int c){
	if(a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if(a > 20 || b > 20 || c > 20)
		return dp(20, 20, 20);
	else if( a < b && b < c){
		if(memo[a][b][c] != 0 )
			return memo[a][b][c];
		else{
			memo[a][b][c] = dp(a, b, c-1) + dp(a, b-1, c-1) - dp(a, b-1, c);
			return memo[a][b][c];
		}
	}else{
		if(memo[a][b][c] != 0 )
			return memo[a][b][c];
		else{
			memo[a][b][c] = dp(a-1, b, c) + dp(a-1, b-1, c) + dp(a-1, b, c-1) - dp(a-1, b-1, c-1);
			return memo[a][b][c];
		}
	}
}