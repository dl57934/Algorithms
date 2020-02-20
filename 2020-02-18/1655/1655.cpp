#include <cstdio>
#include <queue>

using namespace std;

priority_queue< int, vector<int>, less<int> > downQueue; // 큰 값 모둠
priority_queue< int, vector<int>, greater<int> > upQueue; // 작은 값 모둠
int N;

int main(){
	scanf("%d", &N);
	int value;

	for(int i = 1; i <= N; i++){
		scanf("%d", &value);

		if(upQueue.size() == 0){
			upQueue.push(value);
		}else if(upQueue.size() > downQueue.size()){
			downQueue.push(value);
			if(downQueue.top() > upQueue.top()){
				int temp1 = downQueue.top();
				int temp2 = upQueue.top();
				downQueue.pop();
				upQueue.pop();
				upQueue.push(temp1);
				downQueue.push(temp2);
			}
		}else {
			upQueue.push(value);
			if(downQueue.top() > upQueue.top()){
				int temp1 = downQueue.top();
				int temp2 = upQueue.top();
				downQueue.pop();
				upQueue.pop();
				upQueue.push(temp1);
				downQueue.push(temp2);	
			}
		}
		if((downQueue.size() + upQueue.size())%2==0){
			if(downQueue.top() > upQueue.top())
				printf("%d\n", upQueue.top());
			else
				printf("%d\n", downQueue.top());
		}else{
			printf("%d\n", upQueue.top());
		}
	}
}
