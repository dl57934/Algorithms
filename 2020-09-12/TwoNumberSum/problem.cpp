#include <vector>
#include <unordered_set>


using namespace std;
// aimed O(n)

vector<int> twoNumberSum(vector<int> array, int targetSum){
	unordered_set <int> us;

	for(auto num : array)
		us.insert(num);

	for(auto num : array){
		int findNum = targetSum - num;

		if(us.find(findNum) != us.end()){
			return {num, findNum};
		}
	}
}


vector<int> twoNumberSum(vector<int> array, int targetSum){
	unordered_set <int> us;

	for(auto num : array){
		int findNum = targetSum - num;

		if(us.find(findNum) != us.end()){
			return {num, findNum};
		}else {
			us.insert(num);
		}
	}
}