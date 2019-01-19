#include <stdio.h>

int getMid(int N);
int getMode();
int getRange();

int arr[8003] = {0, };

int main(){
	int N;
	int inputNum;
	scanf("%d", &N);
	float elmentSum = 0;
	
	
	for(int i =0; i < N;i++){
		scanf("%d", &inputNum);
		arr[inputNum+4000]+=1;
		elmentSum+=inputNum;
	}
	float average = elmentSum/N;
	int mid = getMid(N);
	int mode = getMode();
	int range = getRange();
	printf("%.0f\n%d\n%d\n%d", average, mid, mode, range);
}

int getMid(int N){
	N/=2;
	int index = 0;
	for(int i = 0; i <= 8000; i++){
		if(arr[i] != 0)
			index += arr[i];
			if(N < index)
				return i-4000;
	}
}

int getMode(){
	int max = 0;
	for(int i = 0; i < 8001; i++){
		if(arr[i] > max)
			max = arr[i];
	}
	int count = 0;
	int mode = 0;
	for(int i = 0; i < 8001; i++){
		if(arr[i] == max){
			count++;
			mode = i;
			if(count == 2)
				break;
		}
	}
	return mode -4000;
}

int getRange(){
	int max=0, min=0;
	for(int i = 0; i <= 8000; i++)
		if(arr[i] != 0){
			min = i;
			break;
		}

	for(int i = 8000; i >= 0; i--)
		if(arr[i] != 0){
			max = i;
			break;
		}

	return max-min;	
}
