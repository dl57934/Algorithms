#include <stdio.h>
#include <string.h>

int numberSet[11] = {0,};

int setSetNumber(int length, char N[]);
int getMaxSet();

int main(){
	char N[9];
	scanf("%s", &N);
	int Nlength = strlen(N);
	printf("%d", setSetNumber(Nlength, N));

}

int setSetNumber(int length, char N[]){
	for(int i = 0; i < length; i++)
		numberSet[N[i]-'0']+=1;
	int result = getMaxSet();
	return result;
}

int getMaxSet(){
	int sumSixNine = numberSet[6] + numberSet[9];
	int max = 0;

	numberSet[6] = sumSixNine/2 + sumSixNine%2;

	for(int i = 0; i < 9; i++){
		if(max < numberSet[i])
			 max = numberSet[i];
	}
	return max;
}