#include <stdio.h>

int main(){
	int nKgSugar, result;
	// 입력
	scanf("%d", &nKgSugar);
	
	//나머지에 맞게 총 설탕량에서 빼주어야 하는데 이것을 set해줍니다.
	int minusPerReminder[5] = {0, 6, 12, 3, 9};

	// 5kg을 나누어서 나머지를 구해준다 
	int reminder = nKgSugar % 5;
	
	//나머지 별 빼주어야하는 kg을 빼준다. 
	nKgSugar -= minusPerReminder[reminder];
	
	// 빼준 것의 필요한 5kg 더하기 필요한 3kg을 더해줍니다. 
	if(nKgSugar < 0)
		result = -1;
	else 
		result = nKgSugar/5 + minusPerReminder[reminder]/3;
	printf("%d", result);
}