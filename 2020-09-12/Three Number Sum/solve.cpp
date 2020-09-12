#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  sort(array.begine(), array.end());
  vector<vector<int>> result;

  while(int i = 0; i < array.size()-2; i++){
  	int target = targetSum - num;
  	int left = i+1, right = array.size() - 1;

  	while(left < right){
  		if(target == array[left] + array[right]){
  			result.push_back({target, array[left], array[right]});
  			left++, right--;
  		}else if(target < array[left] + array[right]){
  			right--;
  		}else{
  			left++;
  		}
  	}
  }


  return result;
}
