#include <cstdio>
#include <string>
#include <stdlib.h>
using namespace std;
char order1[62], order2[62];

int minLength = 999999;

void input();
void setLength(string compare, string base);

int main(){
	input();
	string compare(order1), base(order2);
	int diff = base.size() - compare.size();
	
	for(int i = 0; i <= diff; i++){
		int num = 0;
		for(int comp = 0; comp < compare.size(); comp++){
			if(compare[comp] != base[i + comp]){
				num++;
			}
		}
		if(minLength > num){
			minLength = num;
		}
	}

	printf("%d", minLength);
}

void input(){
	scanf("%s %s", &order1, &order2);
}
