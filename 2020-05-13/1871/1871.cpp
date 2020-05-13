#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;



int main(){
	int T; 

	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		string order;
		string token;
		getline(cin, order);
		
		int firstResult = (order[0]-'A') * 26 * 26+ (order[1]-'A') * 26 + (order[2]-'A') * 1;		
		
		int second = stoi(order.substr(4, 9));
		
		printf("%d %d\n", firstResult, second);
		if(abs(firstResult-second) <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}
}



#include <cstdio>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;



int main(){
	int T; 

	scanf("%d\n", &T);
	for(int i = 0; i < T; i++){
		string order;
		getline(cin, order);
		
		int firstResult = (order[0]-'A') * 26 * 26+ (order[1]-'A') * 26 + (order[2]-'A') * 1;		
		int second = stoi(order.substr(4));
		if(abs(firstResult-second) <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}
}




#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;



int main(){
	int T; 

	scanf("%d\n", &T);
	for(int i = 0; i < T; i++){
		string order;
		string token;
		getline(cin, order);
		
		int firstResult = (order[0]-'A') * (26 ^ 2) + (order[1]-'A') * 26 + (order[2]-'A') * 1;		
		
		int second = stoi(order.substr(4));
		
		printf("%d %d\n", firstResult, second);
		if(abs(firstResult-second) <= 100)
			printf("nice");
		else
			printf("not nice");
	}
}



int main(){
	int T; 

	scanf("%d\n", &T);
	for(int i = 0; i < T; i++){
		string order;
		getline(cin, order);
		
		int firstResult = (order[0]-'A') * (26 ^ 2) + (order[1]-'A') * 26 + (order[2]-'A');		
		
		int second = stoi(order.substr(4));
	
		if(abs(firstResult-second) <= 100)
			printf("nice");
		else
			printf("not nice");
	}
}




int main(){
	int T; 

	scanf("%d\n", &T);
	for(int i = 0; i < T; i++){
		string order;
		getline(cin, order);
		
		int firstResult = (order[0]-'A') * 26 * 26+ (order[1]-'A') * 26 + (order[2]-'A');		
		int second = stoi(order.substr(4));
		if(abs(firstResult-second) <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}
}

