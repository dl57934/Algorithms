#include <cstdio>
#include <vector>

using namespace std;

vector<int> selectNumber(6, 0);
vector<int> allNumber;
vector<int> check(55, 0);
void input();
void back(int limit);

int main(){
	input();
}

void input(){
	int size, number;
	while(scanf("%d", &size)){
		if(size == 0){
			break; 
		}
		
		for(int i = 0; i < size; i++){
			scanf("%d", &number);
			allNumber.push_back(number);
		}
		back(0);
		allNumber.clear();
		selectNumber.clear();
		check.clear();
		printf("\n");
	}	
}

void back(int limit){
	if(limit == 6){
		for(int i = 0; i < 6; i++)
			printf("%d ", selectNumber[i]);
		printf("\n");
		return;
	}

	for(auto number : allNumber){
		if(!check[number] && (selectNumber[limit-1] < number )){
			check[number] = 1;
			selectNumber[limit] = number;
			back(limit+1);
			check[number] = 0;
		}
	}
}