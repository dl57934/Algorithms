#include <stdio.h>
#include <vector>

using namespace std;

vector <char>modification;
int arr[15];
long long maxNumbers = -1000000000;
long long minNumbers = 1000000000;
long long calcul = 0;
int modificationNumbers[5];
int N;

void insertModification(int limit);
void swap(int i,  int j);
int main(){
	modification.reserve(100);
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	calcul = arr[0];

	for(int i = 0; i < 4; i++){
		scanf("%d", &modificationNumbers[i]);
		int vectorSize = modification.size();
		for(int j = vectorSize; j < vectorSize+modificationNumbers[i]; j++){
			if(i == 0)
				modification.push_back('+');
			else if (i == 1)
				modification.push_back('-');
			else if (i == 2)
				modification.push_back('*');
			else if (i == 3)
				modification.push_back('/');
		}
	}

	insertModification(0);

	printf("%lld\n%lld", maxNumbers, minNumbers);
}	

void insertModification(int limit){
	if(limit == N-1){
		for(int i = 1; i <= limit; i++){
			if(modification[i-1] == '+')
				calcul += arr[i];
			else if(modification[i-1] == '-')
				calcul -= arr[i];
			else if(modification[i-1] == '*')
				calcul *= arr[i];
			else if(modification[i-1] == '/')
				calcul /= arr[i];
		}
		if(calcul > maxNumbers)
			maxNumbers = calcul;
		if(calcul < minNumbers)
			minNumbers = calcul;
		calcul = arr[0];
		return;
	}

	for(int i = limit; i < N-1; i++){
		swap(i, limit);
		insertModification(limit+1);
		swap(i, limit);
	}
}

void swap(int i,  int j){
	char temp = modification[i];
	modification[i] = modification[j];
	modification[j] = temp;
}