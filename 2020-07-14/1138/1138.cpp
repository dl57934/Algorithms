#include <cstdio>
#include <algorithm>

using namespace std;
int N;
int arr[12], arr2[12];
void input();

int main(){
	input();
	int person = N;
	for(int per = 0; per < N; per++){
		if(arr2[arr[per]] == 0){
			arr2[arr[per]] = person;
		}else{
			for(int sub = N-1; sub >= arr[per]; sub--){
				arr2[sub+1] = arr2[sub];
			}
			arr2[arr[per]] = person;
		}
		person--;
	}
	for(int i = 0; i < N; i++)	
		printf("%d ", arr2[i]);
}

void input(){
	int num;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}

	reverse(arr, arr+N);
}