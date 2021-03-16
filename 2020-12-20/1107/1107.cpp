#include <cstdio>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
	int N, M, selectButton;
	int breakButton[12] = {0, };
	string inputNumber;

	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < M; i++){
		scanf("%d", &selectButton);
		breakButton[selectButton] = 1;
	}

	int downSelectNumber = -1;
	for(int i = N; i >= 0; i--){
		string inputNumber = to_string(i);
		for(int j = 0; j < inputNumber.size(); j++){
			int now = inputNumber[j] - '0';
			if(breakButton[now] == 0 && j+ 1 == inputNumber.size()){
				downSelectNumber = i;
				break;
			}else if(breakButton[now] == 1)
				break;
		}
		if(downSelectNumber != -1)
			break;
	}	

	int upSelectNumber = -1;
	for(int i = N; i<=1000000; i++){
		string inputNumber = to_string(i);	
		for(int j = 0; j < inputNumber.size(); j++){
			int now = inputNumber[j] - '0';
			if(breakButton[now] == 0 && j+ 1 == inputNumber.size()){
				upSelectNumber = i;
				break;
			}else if(breakButton[now] == 1)
				break;
		}
		if(upSelectNumber != -1)
			break;
	}

	int num = 0;

	if(upSelectNumber == -1 && downSelectNumber != -1){
		num = abs(downSelectNumber - N) + to_string(downSelectNumber).size();
	}else if(upSelectNumber != -1 && downSelectNumber == -1){
		num = abs(upSelectNumber - N) + to_string(upSelectNumber).size();
	}else if(upSelectNumber == -1 && downSelectNumber == -1){
		printf("%d", abs(N - 100));
		return 0;
	}else{
		if(abs(upSelectNumber - N) + to_string(upSelectNumber).size() < abs(downSelectNumber - N) + to_string(downSelectNumber).size()){
			num = abs(upSelectNumber - N) + to_string(upSelectNumber).size();
		}else{
			num = abs(downSelectNumber - N) + to_string(downSelectNumber).size();
		}
	}
	
	if(num < abs(N - 100))
		printf("%d", num);
	else 
		printf("%d", abs(N - 100));
}