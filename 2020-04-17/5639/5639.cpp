#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int size;
int arr[100002];
void input();
void getPostorder(int start, int end);

int main(){
	input();
	getPostorder(0, size);
}

void input(){
	int num;
	while(scanf("%d", &num) != -1){
		arr[size++] = num; 
	}
}


void getPostorder(int start, int end){
	if(start >= end)return;
	int upperIndex = distance(arr, upper_bound(arr+start+1, arr + end, arr[start]));

	getPostorder(start+1, upperIndex);	
	getPostorder(upperIndex, end);
	printf("%d\n", arr[start]);
}
