#include <cstdio>

typedef struct numbers{
	int first;
	int second;
}numbers;

void getStatus(numbers number);

int main(){
	numbers number;
	number.first=1;
	number.second=1;
	for(;;){
		scanf("%d %d", &number.first, &number.second);
		if(number.first ==0  && number.second == 0)
			break;
		getStatus(number);
	}
}

void getStatus(numbers number){
	if(number.second%number.first==0)
		printf("factor\n");
	else if(number.first%number.second==0)
		printf("multiple\n");
	else
		printf("neither\n");

}