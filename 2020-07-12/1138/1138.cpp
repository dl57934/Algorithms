#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr(11, 0);
int result[11];
int N;
void input();

int main(){
	input();
	int sub = N;
	for(int i = 0; i < N; i++){
		if(result[arr[i]] == 0){
			result[i] = sub;
		}else{
			for(int j = N-1; j >= arr[i]; j--){
				result[j+1] = result[j];
			}
			result[arr[i]] = sub;
		}

		sub--;
	}

	for(int i = 0; i < N; i++){
		printf("%d ",result[i]);
	}
}

void input(){
	scanf("%d", &N);
	int num;
	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		arr.push_back(num);
	}
	reverse(arr.begin(), arr.end());
}