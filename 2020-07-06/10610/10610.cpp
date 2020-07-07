#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int size;
char number[1000000];
vector<int> set;
void input();

int main(){
	long long sum = 0;
	int flag = 0;
	input();

	for(int i = 0;  i < size; i++){
		int sub = number[i] - '0';
		sum += sub;

		if(sub == 0){
			flag = 1;
		}
		set.push_back(sub);
	}
	sort(set.begin(), set.end());
	if(flag==0 || sum % 3 != 0){
		printf("-1");
	}else{
		for(int i = set.size()-1; i>=0; i--)
			printf("%d", set[i]);
	}
}

void input(){
	scanf("%s", &number);
	size = strlen(number);
}