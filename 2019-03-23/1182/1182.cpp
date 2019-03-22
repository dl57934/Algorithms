#include <cstdio>

int N, S;
int arr[23];
int find = 0;
int limit = 0;

void swap(int front, int back);
void getSequence(int sum, int index, int count);

int main(){
	scanf("%d %d", &N, &S);

	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for(int i = 0; i < N; i++){
		limit = i;
		getSequence(0, i,  0);		
	}

	printf("%d", find);
}

void getSequence(int sum, int index, int count){
	sum += arr[index];
	if(sum == S)
		find+=1;

	if(count == N-limit)
		return ;

	for(int i = index+1; i < N; i++){
		getSequence(sum, i, count+1);
	}
}

void swap(int front, int back){
	int temp = arr[front];
	arr[front] = arr[back];
	arr[back] = temp;
} 