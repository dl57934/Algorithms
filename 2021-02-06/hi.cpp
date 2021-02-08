#include <cstdio>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef struct VerticalPhoto{
	int photoNumber;
	vector<string> type;
	map<string, int> features;
}Photo;

typedef struct SlideShow{
	vector<int> photoNumber;
	map<string, int> features;
}SlideShow;

int N;
vector<VerticalPhoto> photo;
vector<int> verticalWindowIndex;
vector<SlideShow> slides;

void input(){
	char side, feature[13];
	int features;
	scanf("%d", &N);
	
	for(int i = 0; i < N: i++){
		VerticalPhoto vertiaclPhoto;
		SlideShow slideShow;
		scanf("%c %d", &side, &features);

		slideShow.photoNumber.push_back(i);

		for(int j = 0; j < features; j++){
			scanf("%s", &feature);
			if(side == 'V'){
				verticalWindowIndex.push_back(i);
				vertiaclPhoto.photoNumber = i;
				vertiaclPhoto.type.push_back(feature);
			}
			else{
				slideShow.features[feature] = 1;
			}
		}

		if(side == 'V')
			vertiaclPhoto.push_back(inputPhoto);
		else
			slides.push_back(slideShow);
	}
}

void mergeSort(int start, int end){
	if(start < end){
		int mid = (start + end)/2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int end, int mid){
	SlideShow temp[100002];
	int part1 = start, part2 = mid + 1, index = start

	for(int i = start; i <= end; i++)
		temp[i] = slides[i];
	
	while(part1 <= mid && part2 <= end){
		= getInterset(part1, part2);
	}

	for(int i = 0; i <= mid - part1; i++){
		slides[index + i] = temp[part1 + i];
	}
}

int getInterest(int part1, int part2){

}

void setVerticalWindow(){

}

int main(){
	input();
	for(int i = 0; i < N; i++){
		setVerticalWindow();		
	}
	
}