#include <cstdio>
#include <queue>

using namespace std;

typedef struct _document{
	int order;
	int importance;
}document;

int arr[105];
document doc;
queue <document> qu;

void mergeSort(int start, int end);
void merge(int start, int mid, int end);
void input(int N);
int outputNumber(int N, int M);
void init();

int main(){
	int testCase;
	int N, M;
	
	scanf("%d", &testCase);

	for(int i = 0; i < testCase; i++){
		scanf("%d %d", &N, &M);
		init();
		input(N);
		mergeSort(0, N-1);
		printf("%d\n",outputNumber(N, M));
	}
}

void input(int N){
	for(int i =0; i < N; i++){
		scanf("%d", &doc.importance);
		doc.order = i;
		arr[i] = doc.importance;
		qu.push(doc);
	}
}

void mergeSort(int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		mergeSort(start, mid);
		mergeSort(mid+1, end);
		merge(start, mid, end);
	}
}
void merge(int start, int mid, int end){
	int temp[105];
	for(int i = start; i <= end; i++)
		temp[i] = arr[i];
	int part1 = start;
	int part2 = mid+1;
	int index = start;

	while(part1<=mid && part2<=end){
		if(temp[part1] > temp[part2] ){
			arr[index] = temp[part1];
			part1++;
		}else{
			arr[index] = temp[part2];
			part2++;
		}
		index++;
	}

	for(int i = 0; i <= mid-part1; i++)
		arr[i+index] = temp[i+part1]; 
}


int outputNumber(int N, int M){
	int count = 1;
	int i =0;
	while(i != N){
		int importance = qu.front().importance;
		if( importance != arr[i]){
			qu.push(qu.front());
			qu.pop();
		}else if(importance == arr[i]){
			if(M == qu.front().order)
				return count;
			qu.pop();
			count+=1;
			i+=1;
		}
	}
}

void init(){
	while(!qu.empty())
		qu.pop();
}



