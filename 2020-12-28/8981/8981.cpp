#include <cstdio>

int main(){
	int N, num[101] = {0, }, from = 0, count = 0; 
	int value = 0;
	scanf("%d", &N);

	int subNum;

	for(int i = 0; i < N; i++){
		scanf("%d", &subNum);

		from = ( value + from )% N ; 
		value = num[from]; 

		count++;
		while( value != 0) { 
            from = (from+1)%N; 
            value = num[ from ]; 
        }

        num[from] = subNum;
        value = subNum;
	}

	if(count != N)
		printf("-1");
	else{
		printf("%d\n", count);
    	for(int i = 0; i < N; i++)   
    		printf("%d ", num[i]);
	}
}

// 10
// 1 2 4 8 6 3 7 5 10 9