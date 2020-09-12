#include <vector>

using namespace std;


bool isValidSubsequence(vector<int> array, vector<int> sequence) {
	int arid = 0, sqid = 0;

	if(array.size() < sequence.size())
		return false;

	while(arid < array.size()){
		if(array[arid] == sequence[sqid])
			sqid++;
		
		arid++;
	}
	
	return sqid == sequence.size();
}
