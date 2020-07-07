#include <cstdio>
#include <string>

using namespace std;

int main(){
	char order1[55], order2[55];
	int maxNum = 9876543;
	scanf("%s %s", &order1, &order2);
	string compare(order1), base(order2);

	int diff = base.size() - compare.size();

	for(int df = 0; df <= diff; df++){
		int sub = 0;
		for(int i = 0; i < compare.size(); i++){
			if(compare[i] != order2[i+df]){
				sub++;
			}
		}
		if(maxNum > sub)
			maxNum = sub;
	}

	printf("%d", maxNum);
}