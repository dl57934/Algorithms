#include <cstdio>
#include <stdlib.h>

int N;
long long arr[200005];
long long size = 0;

void push(long long value);
long long popTop();

int isBothEmpty(long long index);
int isLeftEmpty(long long index);
int isRightEmpty(long long index);
long long returnAbs(long long value);
long long onlyLeftCalculator(long long value, long long index);
long long onlyRightCalculator(long long value, long long index);

int main(){
	scanf("%d", &N);
	long long value = 0; 
	for(int i = 0; i < N; i++){
		scanf("%lld", &value);
		if(value == 0){
			if(size == 0)
				printf("0\n");
			else
				printf("%lld\n", popTop());
		}else{
			push(value);
		}

		// for(int i = 1 ; i <= size; i++)
		// 	printf("%lld ", arr[i]);
		// printf("\n");
	}
}

void push(long long value){	
	size++;
	long long index = size;

	while(index!=1 && abs(value) <= abs(arr[index/2])){
		if(abs(value) < abs(arr[index/2])){
			arr[index] = arr[index/2];
			index/=2;
		}else if(abs(value) == abs(arr[index/2])){
			if(value < arr[index/2]){
				arr[index] = arr[index/2];
				index/=2;
			}
			else break;
		}
	}

	arr[index] = value;
}

long long popTop(){
	long long returnValue = arr[1];
	long long index = 1;
	long long value = arr[size];
	arr[size] = 0;
	size-=1;

	while(index < size){
		if(isBothEmpty(index))
			break;

		if(returnAbs(arr[index * 2]) > returnAbs(value) && returnAbs(arr[index * 2 + 1]) > returnAbs(value))
			break;

		if(isLeftEmpty(index)){
			long long result = onlyRightCalculator(value, index);
				if(result == 0)
					break;
				else 
					index = result;
		}else if(isRightEmpty(index)){
			long long result = onlyLeftCalculator(value, index);
				if(result == 0)
					break;
				else 
					index = result;
		}else{
			if(returnAbs(arr[index * 2]) <= returnAbs(value) || returnAbs(arr[index * 2 + 1]) <= returnAbs(value)){
				if(returnAbs(arr[index * 2]) <= returnAbs(value) && returnAbs(arr[index * 2 + 1]) <= returnAbs(value)){
					if(returnAbs(arr[index * 2]) <= returnAbs(value) && returnAbs(arr[index * 2 + 1]) <= returnAbs(value)){
						if(returnAbs(arr[index * 2]) < returnAbs(arr[index * 2 + 1])){
							arr[index] = arr[index * 2];
							index = index * 2;
						}else if(returnAbs(arr[index * 2]) > returnAbs(arr[index * 2 + 1])){
							arr[index] = arr[index * 2 + 1];
							index = index * 2 + 1;
						}else {
							if(arr[index * 2] <= arr[index * 2 +1]){
								arr[index] = arr[index * 2];
								index = index * 2;
							}else{
								arr[index] = arr[index * 2 + 1];
								index = index * 2 + 1;
							}
						}
					}
				}else if(returnAbs(arr[index * 2]) <= returnAbs(value)){
					long long result = onlyLeftCalculator(value, index);
					if(result == 0)
						break;
					else 
						index = result;
				}else if(returnAbs(arr[index * 2 + 1]) <= returnAbs(value)){
					long long result = onlyRightCalculator(value, index);
					if(result == 0)
						break;
					else 
						index = result;
				}
			}
		}
	}
	arr[index] = value;

	return returnValue;
}


int isBothEmpty(long long index){
	if(arr[index * 2] == 0 && arr[index * 2 + 1] == 0)
		return 1;
	else 
		return 0;
}
int isLeftEmpty(long long index){
	if(arr[index * 2] == 0 && arr[index * 2 + 1] != 0)
		return 1;
	else 
		return 0;	

}
int isRightEmpty(long long index){
	if(arr[index * 2] != 0 && arr[index * 2 + 1] == 0)
		return 1;
	else 
		return 0;
}

long long returnAbs(long long value){
	return abs(value);
}

long long onlyLeftCalculator(long long value, long long index){
	if(returnAbs(arr[index * 2]) < returnAbs(value)){
		arr[index] = arr[index * 2];
		return index * 2;					
	}else if(returnAbs(arr[index * 2]) == returnAbs(value)){
		if(arr[index * 2] == value || arr[index * 2] < value){
			arr[index] = arr[index * 2];
			return index * 2;					
		}else return 0;
	}else 
		return 0;
}

long long onlyRightCalculator(long long value, long long index){
	if(returnAbs(arr[index * 2 + 1]) < returnAbs(value)){
			arr[index] = arr[index * 2 + 1];
			return index * 2 + 1;					
	}else if(returnAbs(arr[index * 2 + 1]) == returnAbs(value)){
		if(arr[index * 2 + 1] == value || arr[index * 2 + 1] < value){
			arr[index] = arr[index * 2 + 1];
			return index * 2 + 1;					
		}else return 0;
	}
	else 
		return 0;
}
