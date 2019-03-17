#include <stdio.h>

typedef struct _subjectByUser{
	char subjectName[104];
	int subjectNumber;
	char grade[4];
}subjectInfoByUser;

int allSubjectNumber;
subjectInfoByUser user; 
void calculate(float base);
void whatIsGrade(char grade);

double sum = 0.0; 

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s %d %s", user.subjectName, &user.subjectNumber, user.grade);
		whatIsGrade(user.grade[0]);
		allSubjectNumber+=user.subjectNumber;
	}
	
	float result = sum/allSubjectNumber;
	printf("%.2f\n", result);
}

void whatIsGrade(char grade){
	if(grade == 'A')
		calculate(4.0);
	else if(grade == 'B')
		calculate(3.0);
	else if(grade == 'C')
		calculate(2.0);
	else if(grade == 'D')
		calculate(1.0);
}

void calculate(float base){
		float appendNumber = 0.0;
		if(user.grade[1] == '+')
			appendNumber = 0.3;
		else if(user.grade[1] == '-')
			appendNumber = -0.3;
		sum += (base + appendNumber) * user.subjectNumber;
}