#include <cstdio>
#include <string>
#include <math.h>

using namespace std;

int main(){
	int N, findSeriseNum=0;
	scanf("%d", &N);
	string sixsixsix = "666"; 
	int seriseNumber = 666;

	while(findSeriseNum < N){
		string numbers = to_string(seriseNumber);

		if(numbers.find(sixsixsix) != string::npos)			
			findSeriseNum+=1;
		seriseNumber+=1;
	}



	printf("%d", seriseNumber-1);
}

