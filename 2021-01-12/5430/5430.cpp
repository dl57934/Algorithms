#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

void solve();

int main(){
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; i++)
		solve();
}

void solve(){
	char p[100002];
	int num;
	deque<int> dq;

	scanf("%s %d", &p, &num);

	char item;
	int numsize = 0;
	int value = 0, slasherNum = 100;
	while(1){
		scanf(" %c", &item);
		if(item >= '0' && item <= '9'){
			value += (item-'0') * slasherNum;
			numsize+=1;
			slasherNum/=10;
		}else if(item == ']' || item == ','){
			if(numsize == 1)
				dq.push_back(value / 100);
			else if(numsize == 2)
				dq.push_back(value / 10);
			else{
				if(value != 0)
					dq.push_back(value);
			}

			numsize = 0;
			value = 0;
			slasherNum = 100;
			if(item == ']')
				break;
		}
	}

	int orderSize = strlen(p);

	int isFront = 1;
	for(int i = 0; i < orderSize; i++){
		if(p[i] == 'R'){
			isFront = !isFront;
		}else if(p[i] == 'D'){
			if(dq.size() == 0){
				printf("error\n");
				return;
			}
			else{
				if(isFront){
					dq.pop_front();
				}else{
					dq.pop_back();
				}
			}
		}
	}

	printf("[");
	while(!dq.empty()){
		if(isFront){
			if(dq.size() == 1)
				printf("%d", dq.front());
			else
				printf("%d,", dq.front());

			dq.pop_front();
		}else{
			if(dq.size() == 1)
				printf("%d", dq.back());
			else
				printf("%d,", dq.back());

			dq.pop_back();
		}
	}

	printf("]\n");
}