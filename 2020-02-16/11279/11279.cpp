#include <stdio.h>

int N;

long long data[200010];
int size = 0;

void input(long long value);
long long removeValue();

int main(){
	scanf("%d", &N);
	long long value;
	for(int i = 0; i < N; i++){
		scanf("%lld", &value);
		if(value == 0){
			if(size == 0 )
				printf("0\n");
			else
				printf("%lld\n", removeValue());
		}
		else
			input(value);
	}
}

void input(long long value){
	size+=1;
	int index = size;

	while(index !=1 && data[index/2] <= value){
		data[index] = data[index/2];
		index/=2;
	}

	data[index] = value;
}

long long removeValue(){
	long long returnValue = data[1];
	long long value = data[size];
	int index = 1;
	data[size] = 0;
	size-=1;

	while(index < size){	
		if(value > data[index*2 + 1] && value > data[index*2])
			break;		

		if(value <= data[index*2 + 1] || value <= data[index*2] ){
			if(data[index * 2] < data[index*2 + 1]){
				data[index] = data[index * 2 + 1];
				index = index*2+1;
			}
			else{
				data[index] = data[index * 2];
				index*=2;
			}
		}
	}

	data[index] = value;

	return returnValue;
}




