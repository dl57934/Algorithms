#include <cstdio>
#include <vector>

using namespace std;
#define ll long long
int N;
vector<int> number(15);
vector<char> operand;
int visited[15];
char arr[15];

ll maxResult = -1000000001, minResult = 1000000001;

void backTrack(int limit);

int main(){
	int oper;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &number[i]);
	}

	for(int i = 0; i < 4; i++){
		scanf("%d", &oper);
		for(int j = 0; j < oper; j++){
			if(i == 0){
				operand.push_back('+');
			}else if(i == 1){
				operand.push_back('-');
			}else if(i == 2){
				operand.push_back('*');
			}else if(i == 3){
				operand.push_back('/');
			}
		}
	}



	backTrack(0);

	printf("%lld\n%lld", maxResult, minResult);
}


void backTrack(int limit){
	if(limit == N-1){
		ll result = number[0];
		for(int i = 0; i < N-1; i++){
			if(arr[i] == '+'){
				result = result + number[i+1];
			}else if(arr[i] == '-'){
				result = result - number[i+1];
			}else if(arr[i] == '*'){
				result = result * number[i+1];
			}else if(arr[i] == '/'){
				result = result / number[i+1];
			}
		}

		if(maxResult < result){
			maxResult = result;
		}

		if(minResult > result){
			minResult = result;
		}
		return ;
	}

	for(int i = 0; i < N-1; i++){
		if(visited[i] == 0){
			visited[i] = 1;
			arr[limit] = operand[i];
			backTrack(limit+1);
			visited[i] = 0;
		}
	}
}