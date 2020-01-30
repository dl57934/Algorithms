#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

char string1[1003], string2[1003];
int dp[1003][1003] = {};

int main(){
	scanf("%s", string1);
	scanf("%s", string2);
	int length1 = strlen(string1);
	int length2 = strlen(string2);

	for(int i = 1; i <= length1; i++){
		for(int j = 1; j <= length2; j++){
			if(string1[i-1] == string2[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}

	int max = 0;

	for(int i = 1; i <= length1; i++)
		if(max < *max_element(dp[i], dp[i]+length2+1))
			max = *max_element(dp[i], dp[i]+length2+1);

	printf("%d", max);
}