#include <cstdio>
#include <string>

using namespace std;

string origin, target;
int pi[360002];
int line;

void getPi();
int isSameClock();

int main(){
	scanf("%d", &line);

	for(int i = 0; i < 360000; i++){
		origin.push_back('0');
		target.push_back('0');
	}
	int num = 0;

	for(int i = 0; i < line; i++){
		scanf("%d", &num);
		origin[num] = '1';
	}

	for(int i = 0; i < line; i++){
		scanf("%d", &num);
		target[num] = '1';
	}

	origin = origin + origin;
	if(isSameClock())
		printf("possible");
	else
		printf("impossible");
}

void getPi(){
	int begin = 1, matched = 0;
	while(begin + matched < target.size()){
		if(target[begin + matched] == target[matched]){
			matched++;
			pi[begin+matched-1] = matched;
		}else {
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}	
		}
	}
}

int isSameClock(){
	int begin = 0, matched = 0;
	int targetSize = target.size();
	int originSize = origin.size();
	getPi();

	while( begin <=  (originSize - targetSize)){
		if(origin[begin + matched] == target[matched] && matched < targetSize){
			matched++;
			if(matched == targetSize) return 1;
		}else {
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}	
		}
	}
	return 0;
}