#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;



typedef struct Pizza{
	vector<string> ingredients;
}Pizza;

typedef struct TwoTeam{
	map<string, int> notDuplicationIngredients;
	vector<int> selectionPizza;

	bool isHaveIngredients(string ingredients){
		if(notDuplicationIngredients.find(ingredients) != notDuplicationIngredients.end())
			return true;
		return false;
	}
}TwoTeam;

typedef struct ThreeTeam{
	map<string, int> notDuplicationIngredients;
	vector<int> selectionPizza;
	bool isHaveIngredients(string ingredients){
		if(notDuplicationIngredients.find(ingredients) != notDuplicationIngredients.end())
			return true;
		return false;
	}
}ThreeTeam;

typedef struct FourTeam{
	map<string, int> notDuplicationIngredients;
	vector<int> selectionPizza;
	bool isHaveIngredients(string ingredients){
		if(notDuplicationIngredients.find(ingredients) != notDuplicationIngredients.end())
			return true;
		return false;
	}
}FourTeam;

int allPizza, twoTeamSize, threeTeamSize, fourTeamSize;
Pizza pizzaInfo[100002];
TwoTeam twoTeam[50002];
ThreeTeam threeTeam[50002];
FourTeam fourTeam[50002];
vector<int> remainPizzaIndex;
void solve();

int main(){
	int ingredientSize;
	char ingredient[25];
	scanf("%d %d %d %d", &allPizza, &twoTeamSize, &threeTeamSize, &fourTeamSize);

	for(int i = 0; i < allPizza; i++){
		remainPizzaIndex.push_back(i);
		scanf("%d", &ingredientSize);
		for(int ingredientIndex = 0; ingredientIndex < ingredientSize; ingredientIndex++){
			scanf("%s", &ingredient);
			string strIngredients(ingredient);
			pizzaInfo[i].ingredients.push_back(strIngredients);
		}
	}

	solve();
}

int arr[5], maximumIndex[5];
int value = 0;

void selectionMaxinumValuePizza(int size, int limit, int visited[]){
	if(limit == size){
		map<string, int> allIngredient;
		int ingredientNumber = 0;
		for(int i = 0; i < size; i++){
			for(auto ing : pizzaInfo[arr[i]].ingredients){
				if(allIngredient.find(ing) == allIngredient.end()){
					ingredientNumber++;
					allIngredient[ing] = 1;
				}
			}

		}



		if(value < ingredientNumber){
			value = ingredientNumber;
			for(int i = 0; i < 4; i++)
				maximumIndex[i] = arr[i];
		}

		return ;
	}

	for(int i = 0; i < allPizza; i++){
		if(visited[i] == 0 && (arr[limit-1] < i  || limit == 0)){
			visited[i] = 1;
			arr[limit] = i;
			selectionMaxinumValuePizza(size, limit+1, visited);
			visited[i] = 0;		
		}
	}
}

void clear(){
	value = 0;
}

int selectionFourTeamSize, selectionThreeTeamSize, selectionTwoTeamSize;

void fourTeamMaxinumValue(){
	for(int four = 0; four < fourTeamSize; four++){
		int visited[100002] = { 0, };
		
		if(allPizza < 4)
			break;
		selectionFourTeamSize = four+1;
		selectionMaxinumValuePizza(4, 0, visited);
		clear();
		for(int i = 0; i < 4; i++){
			fourTeam[four].selectionPizza.push_back(maximumIndex[i]);
			remove(remainPizzaIndex.begin(), remainPizzaIndex.end(), maximumIndex[i]); 
		}

		allPizza-=4;
	}

}

void threeTeamMaxinumValue(){
	for(int three = 0; three < threeTeamSize; three++){
		int visited[100002] = { 0, };
		
		if(allPizza < 3)
			break;
		selectionThreeTeamSize = three+1;
		selectionMaxinumValuePizza(3, 0, visited);
		clear();
		for(int i = 0; i < 3; i++){
			threeTeam[three].selectionPizza.push_back(maximumIndex[i]);
			remove(remainPizzaIndex.begin(), remainPizzaIndex.end(), maximumIndex[i]); 
		}

		allPizza-=3;
	}
}

void twoTeamMaxinumValue(){
	for(int two = 0; two < twoTeamSize; two++){
		int visited[100002] = { 0, };
		
		if(allPizza < 2)
			break;
		selectionTwoTeamSize = two+1;
		selectionMaxinumValuePizza(2, 0, visited);
		clear();
		for(int i = 0; i < 2; i++){
			twoTeam[two].selectionPizza.push_back(maximumIndex[i]);
			remove(remainPizzaIndex.begin(), remainPizzaIndex.end(), maximumIndex[i]); 
		}

		allPizza-=2;
	}
}

void solve(){
	fourTeamMaxinumValue();
	threeTeamMaxinumValue();
	twoTeamMaxinumValue();

	printf("%d\n", selectionFourTeamSize + selectionThreeTeamSize + selectionTwoTeamSize);

	if( selectionTwoTeamSize != 0){
		printf("2 ");
		for(int two = 0; two < selectionTwoTeamSize; two++){
			for(int i = 0; i < 2; i++){
				printf("%d ", twoTeam[two].selectionPizza[i]);
			}
		}
		printf("\n");
	}
	
	if(selectionThreeTeamSize != 0){
		printf("3 ");
		for(int three = 0; three < selectionThreeTeamSize; three++){
			for(int i = 0; i < 3; i++){
				printf("%d ", threeTeam[three].selectionPizza[i]);
			}
		}
		printf("\n");
	}

	
	if(selectionFourTeamSize != 0){
		printf("4 ");
		for(int four = 0; four < selectionFourTeamSize; four++){
			for(int i = 0; i < 4; i++){
				printf("%d ", fourTeam[four].selectionPizza[i]);
			}
		}
	}
}