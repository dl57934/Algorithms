#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

typedef struct Point{
	float x, y;
	int index;
}Point;

typedef struct Disjoint{
	vector<Point> point;

	void set(Point subPoint){
		point.push_back(subPoint);
	}

	Point find(Point subPoint){
		if(subPoint.x == point[subPoint.index].x && subPoint.y == point[subPoint.index].y ){
			return subPoint;
		}
		return point[subPoint.index] = find(point[subPoint.index]);
	}

	void merge(Point a, Point b){
		a = find(a), b= find(b);

		if(a.x == b.x && a.y == b.y)
			return;

		point[a.index] = b;
	}
}Disjoint;

bool cmp(const pair<float, pair<Point, Point> > &p1, const pair<float, pair<Point, Point> > &p2){
    if(p1.first < p2.first){
        return true;
    }
    return false;
}

vector<Point> vertex;
vector<pair<float, pair<Point, Point> > >  edge;
int N;

int main(){
	float x, y, result = 0;
	scanf("%d", &N);
	Disjoint disjoint;
	
	for(int i = 0; i < N; i++){
		scanf("%f %f", &x, &y);
		Point newPoint = {x, y, i};
		disjoint.set(newPoint);
		vertex.push_back(newPoint);
	}

	for(int y = 0; y < vertex.size(); y++){
		for(int x = y+1; x < vertex.size(); x++){
			Point u = vertex[y], d = vertex[x];
			float cost = sqrt(pow(fabs(u.x - d.x),2) + pow(fabs(u.y - d.y), 2));
			edge.push_back(make_pair(cost, make_pair(u, d)));
		}
	}

	sort(edge.begin(), edge.end(), cmp);


	for(auto ed : edge){
		float cost = ed.first;
		Point u = ed.second.first, d = ed.second.second;
		u = disjoint.find(u), d = disjoint.find(d);

		if(u.x == d.x && u.y == d.y) 
			continue;

		disjoint.merge(u, d);

		result += cost;
	}

	printf("%.2f", result);
}


















#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[]){
	int fd, id;
	struct student rec;
	struct flock lock;

	if(argc < 2){
		fprintf(stderr, "사용법: %s 파일 \n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDWR)) == -1){
		perror(argv[1]);
		exit(2);
	}

	printf("\n 수정할 학생의 학번 입력");
	while(scanf("%d", &id) == 1){
		lock.l_type = F_WRLCK;
		lock.l_where = SEEK_SET;
		lock.l_start = (id - START_ID) * sizeof(rec);
		lock.l_len = sizeof(rec);

		if(fcntl(fd, F_SETLKW, &lock) == -1){
			perror(argv[1]);
			exit(3);
		}

		lseek(fd, (long) (id-START_ID) * sizeof(rec), SEEK_SET);
		if((read(fd, &rec, sizeof(rec)) > 0) && (rec.id != 0))
			printf("이름:%s \t 학번:%d\t 점수:%d\n", rec.name, rec.id, rec.score);
		else printf("레코드 없음 %d 없음\n", id);

		printf("새로운 점수: ");
		scanf("%d", &rec.score);
		lseek(fd, (long) - sizeof(rec), SEEK_CUR);
		write(fd, (char *) &record, sizeof(record));

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);  /* 잠금 해제 */
        printf("\n수정할 학생의 학번 입력:");
	}
	close(fd);
	exit(0);
}



