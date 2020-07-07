#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> result;
long long maxValue = 0;
long long minValue = 9876543210;
char inequality[12];
char numbers[16];
int check[12];
int arr[12];
int N;
void input();
void back(int limit);
int isValidCompare(int limit, int compareValue);

int main(){
	input();
	back(0);
	sort(result.begin(), result.end());
	printf("%s\n%s",result.back().c_str(), result[0].c_str());
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf(" %c", &inequality[i]);
}


void back(int limit){
	if(limit == N+1){
		string value;
		for(int i = 0; i < limit; i++){
			value+=arr[i]+'0';
		}
		
		result.push_back(value);

		return;
	}

	for(int i = 0; i <= 9; i++){
		if(check[i] == 0){
			if(isValidCompare(limit, i) || limit == 0){
				check[i] = 1;
				arr[limit] = i;
				back(limit+1);
				check[i] = 0;
			}
		}
	}
}

int isValidCompare(int limit, int compareValue){
	if(inequality[limit-1] == '>'){
		if(arr[limit-1] > compareValue)
			return 1;
		else
			return 0;
	}else{
		if(arr[limit-1] < compareValue)
			return 1;
		else
			return 0;
	}
}