#include <cstdio>
#include <queue>

using namespace std;
	
long long arr[200010];
int N;

void push(long long value);
long long removeElement();

priority_queue< long long, vector<long long>, greater<long long> > pq;

int main(){
	scanf("%d", &N);

	long long value;
	for(int i = 0; i < N; i++){
		scanf("%lld", &value);
		if(value == 0){
			if(pq.size() == 0)
				printf("0\n");
			else 
				printf("%lld\n", removeElement());
		}	
		else
			push(value);
	}
}


void push(long long value){
	pq.push(value);
}

long long removeElement(){
	long long returnValue = pq.top();
	pq.pop();
	return returnValue;
}