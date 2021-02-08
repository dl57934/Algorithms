#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

typedef struct Library{
	vector<pair<int, int> > books;
	ll worth;
	int signUpTime, shipBooksPerDay, itCanScan;
	int signUpStartDay, signUpEndDay;

	void setTime(int signUpTime, int shipBooksPerDay){
		this->itCanScan = 0;
		this->signUpTime = signUpTime;
		this->shipBooksPerDay = shipBooksPerDay;
		this->worth = 0;
	}

	void addBooks(int value, int bookIdx){
		books.push_back(make_pair(value, bookIdx));
		this->worth+= value;
	}

}Library;

int bookValue[100002];
int duplicationBooks[100002];

int books, librarys, days;
vector<Library*> vc;
void mergeSort(int start, int end);
void merge(int start, int mid, int end);

pair<int, int> getSortWorth(int libraryIndex){
	pair<int, int> worthAndDay;
	worthAndDay.first = vc[libraryIndex]->worth;
	worthAndDay.second = vc[libraryIndex]->signUpTime + vc[libraryIndex]->books.size()%vc[libraryIndex]->shipBooksPerDay == 0?
	vc[libraryIndex]->books.size()/vc[libraryIndex]->shipBooksPerDay 
	: vc[libraryIndex]->books.size()/vc[libraryIndex]->shipBooksPerDay + 1;
	return worthAndDay;
}

void mergeSort(int start, int end){
	if(start < end){
		int mid = (start + end)/2;
		mergeSort(start, mid);
		mergeSort(mid+1, end);
		merge(start, mid, end);
	}
}

void removeDuplication(){
	for(int library = 0; library < librarys; library++){
		if(library == 0){
			for(auto book : vc[library]->books)
				duplicationBooks[book.second] = 1;
		}else{
				vector<pair<int, int> >::iterator it = vc[library]->books.begin();
				while (it != vc[library]->books.end()) {
					if(duplicationBooks[it->second] == 1){
						it = vc[library]->books.erase(it);
					}else{
						duplicationBooks[it->second] = 1;
						++it;
					}
           		}
		}
	}
}

void merge(int start, int mid, int end){
	int part1 = start, part2 = mid+1, index = start;
	vector<Library*> temp(100002);
	for(int i = start; i <= end; i++ ){
		temp[i] = vc[i];
	}

	while(part1 <= mid && part2 <= end){
		pair<int, int> compareLibrary1 = getSortWorth(part1), compareLibrary2 = getSortWorth(part2);
		if(compareLibrary1.first > compareLibrary2.first && compareLibrary1.second < compareLibrary2.second){
			vc[index] = temp[part1];
			part1++;
		}else if((compareLibrary1.first == compareLibrary2.first && compareLibrary1.second < compareLibrary2.second) && 
			(compareLibrary1.first > compareLibrary2.first && compareLibrary1.second == compareLibrary2.second)){
			vc[index] = temp[part1];
			part1++;
		}else{
			vc[index] = temp[part2];
			part2++;
		}

		index++;
	}

	for(int i = 0; i <= mid - part1; i++){
		vc[i + index] = temp[part1 + i];
	}
}

void input(){
	scanf("%d %d %d", &books, &librarys, &days);

	for(int i = 0; i < books; i++)
		scanf("%d", &bookValue[i]);

	int libraryBooks, signUpTime, shipBooksPerDay, bookIdx;

	for(int i = 0; i < librarys; i++){
		Library *library = new Library();
		scanf("%d %d %d", &libraryBooks, &signUpTime, &shipBooksPerDay);
		library->setTime(signUpTime, shipBooksPerDay);
		for(int j = 0; j < libraryBooks; j++){
			scanf("%d", &bookIdx);
			library->addBooks(bookValue[bookIdx], bookIdx);
		}

		sort(library->books.begin(), library->books.end(), greater<pair<int, int> > ());

		vc.push_back(library);
	}
}

void solve(){
	mergeSort(0, vc.size()-1);

	removeDuplication();
	mergeSort(1, vc.size()-1);
	int tempDay = 0;

	for(int index = 0; index < librarys; index++){
		printf("library %d size %d\n", index, vc[index]->books.size());
	}
	ll allWorth = 0;

	for(int day = 0; day < days; day++){
		for(int libraryIndex = 0; libraryIndex < librarys; libraryIndex++){
			if((day-tempDay) == vc[libraryIndex]->shipBooksPerDay-1 && !vc[libraryIndex]->itCanScan){
				tempDay+=vc[libraryIndex]->shipBooksPerDay;
				vc[libraryIndex]->itCanScan = 1;
				continue;
			}

			if(!vc[libraryIndex]->itCanScan)
				break;

			if(vc[libraryIndex]->itCanScan){
				for(int i = 0; i < vc[libraryIndex]->shipBooksPerDay; i++){
					if(vc[libraryIndex]->books.size() > 0){
						allWorth+=vc[libraryIndex]->books[0].first;
						vc[libraryIndex]->books.erase(vc[libraryIndex]->books.begin());
					}else{
						break;
					}
				}
			}
		}
	}

	printf("%lld", allWorth);
}

int main(){
	input();
	solve();
}