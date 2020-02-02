#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[1003][1003];

int main(){
	char letter1[1003];
	char letter2[1003];

	scanf("%s", letter1);
	scanf("%s", letter2);

	int length1 = strlen(letter1);
	int length2 = strlen(letter2);

	for(int i = 1; i <= length1; i++){
		for(int j = 1; j <= length2; j++){
			if(letter1[i-1] == letter2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	printf("%d", dp[length1][length2]);
}