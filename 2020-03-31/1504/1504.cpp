#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef struct _info{
	int weight;
	int point;
} Info;

int N, E, firstPoint, secondPoint;
int distances[802];
int INF = 987654321;

struct cmp{
    bool operator()(Info t, Info u){
        return t.weight < u.weight;
    }
};

vector <Info>map[802]; // weight end


void input();
void set(int start);
int Dajickstar(int start, int end);

int main(){
	input();
	int first1, second1, third1;
	int first2, second2, third2;
		
		first1 = Dajickstar(1, firstPoint);
		second1 = Dajickstar(firstPoint, secondPoint);
		third1 = Dajickstar(secondPoint, N);
		int example1 = first1 + second1 + third1;

		first2 = Dajickstar(1, secondPoint);
		second2 = Dajickstar(secondPoint, firstPoint);
		third2 = Dajickstar(firstPoint, N);
		int example2 = first2 + second2 + third2;

		if(example1 < example2){
			if(first1 == INF || second1 == INF || third1 == INF)
				printf("-1");
			else
			printf("%d", example1);
		}
		
		else{
			if(first2 == INF || second2 == INF || third2 == INF)
				printf("-1");
			else
				printf("%d", example2);
		}
			
}


void input(){
	Info inputPoint;
	int start, end, weight;
	scanf("%d %d", &N, &E);
	for(int i = 0; i < E; i++){
		scanf("%d %d %d", &start, &end, &weight);
		inputPoint.weight = weight;
		inputPoint.point = end;
		map[start].push_back(inputPoint);
		inputPoint.point = start;
		map[end].push_back(inputPoint);
	}
	scanf("%d %d", &firstPoint, &secondPoint);
}

void set(int start){
	for(int i = 1; i <= N; i++){
		distances[i] = INF;
	}
	distances[start] = 0;
}

int Dajickstar(int start, int end){
	priority_queue <Info, vector<Info>, cmp > qu;
	Info startPoint = {0, start};
	qu.push(startPoint);
	set(start);
	while(!qu.empty()){
		Info now = qu.top();
		int weight = now.weight;
		int nowPoint = now.point;
		qu.pop();
		for(int i = 0; i < map[nowPoint].size(); i++){
			Info next = map[nowPoint][i];
			int moveWeight = next.weight;
			int nextPoint = next.point;
			
				if(distances[nextPoint] > moveWeight + weight){
					distances[nextPoint] = moveWeight + weight;
					Info newPoint;
					newPoint.weight = distances[nextPoint];
					newPoint.point = nextPoint;
					qu.push(newPoint);
				}
		}
	}
	return distances[end];
}